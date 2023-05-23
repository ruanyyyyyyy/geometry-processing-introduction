#include "euler_characteristic.h"

int euler_characteristic(const Eigen::MatrixXi &F) {
    int Chi = 0;
    // ADD YOUR CODE HERE
    std::set<int> vertex;
    for (int i = 0; i < F.cols(); i++) {
        for (int j = 0; j < F.rows(); j++) {
            vertex.insert(F(j, i));
        }
    }
    int vertex_cnt = vertex.size();
    int edge_cnt = edges(F).rows();
    int face_cnt = F.rows();
    Chi = vertex_cnt - edge_cnt + face_cnt;
    return Chi;
}
