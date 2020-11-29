//
// Created by leohao on 2020/11/29.
//
#include <iostream>
#include <cmath>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char **argv){
    // 旋转矩阵， 旋转向量， 欧拉角， 欧式变换，四元数
    Matrix3d rotation_matrix = Matrix3d::Identity(); // 用单位矩阵进行初始化
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));
    cout.precision(3);
    cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();

    Vector3d v(1, 0, 0);
    Vector3d v_rotated  = rotation_vector * v;
    cout << "(1, 0, 0) after rotation (by angle axis) = " << v_rotated.transpose() << endl;
    v_rotated = rotation_matrix * v;
    cout << "(1, 0, 0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // zyx顺序
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    Isometry3d T = Isometry3d::Identity(); // 实质上是4维
    T.rotate(rotation_vector);
    T.pretranslate((Vector3d(2, 3, 4))); // 平移向量
    cout << "Transfrom matrix = \n" << T.matrix() << endl;

    Vector3d v_transformed = T * v; // = R * v + t
    cout << "v transformed = " << v_transformed.transpose() << endl;

    Quaterniond q = Quaterniond(rotation_vector);// w,x,y,z
    cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl; // coeffs的顺序(x, y, z, w), w为实部
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;

    v_rotated = q * v; // 数学上是 q * v * q^-1
    cout << "(1, 0, 0) after rotation (by quaternion) = " << v_rotated.transpose() << endl;
    cout << "equal to : " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;

    return 0;
}

