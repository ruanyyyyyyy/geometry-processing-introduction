#include "edges.h"

/************* Test example ********************/
/*Eigen::MatrixXi a(2, 3);
a << 1, 2, 3,
1, 4, 2;*/
/************* Correct output ******************/
/*1 2
2 3
3 1
1 4
4 2*/

Eigen::MatrixXi edges(const Eigen::MatrixXi &F) {
    Eigen::MatrixXi E;
    // ADD YOUR CODE HERE
    std::vector <std::vector<int>> temp;

    std::set <std::pair<int, int>> a_set;
    std::pair<int, int> p;
    for (int i = 0; i < F.rows(); i++) {
        p.first = F(i, 0);
        p.second = F(i, 1);
        if (a_set.count(p) == 0) {
            a_set.insert(std::pair<int, int>(F(i, 0), F(i, 1)));
            a_set.insert(std::pair<int, int>(F(i, 1), F(i, 0)));

            temp.push_back({F(i, 0), F(i, 1)});
        }

        p.first = F(i, 1);
        p.second = F(i, 2);
        if (a_set.count(p) == 0) {
            a_set.insert(std::pair<int, int>(F(i, 1), F(i, 2)));
            a_set.insert(std::pair<int, int>(F(i, 2), F(i, 1)));

            temp.push_back({F(i, 1), F(i, 2)});
        }

        p.first = F(i, 2);
        p.second = F(i, 0);
        if (a_set.count(p) == 0) {
            a_set.insert(std::pair<int, int>(F(i, 2), F(i, 0)));
            a_set.insert(std::pair<int, int>(F(i, 0), F(i, 2)));

            temp.push_back({F(i, 2), F(i, 0)});
        }
    }

    E.resize(temp.size(), 2);

    for(int i = 0; i < temp.size(); i++) {
        for(int j = 0; j < temp[0].size(); j++) {
            E(i, j) = temp[i][j];
        }
    }

    /******* debug *********/
    /*for(auto it=temp.begin(); it!=temp.end(); ++it) {
         for(auto it2=it->begin(); it2 != it->end(); ++it2) {
             std::cout << *it2 << " ";
         }
         std::cout << std::endl;
     }*/

    return E;
}
