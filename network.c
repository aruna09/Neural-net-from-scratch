#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

no_neurons = 10;
no_pixels = 100
/*
Each row has 100 columns. Each layer is also gonna have 100 neurons,
therefore 100 structures. There are two arrays
*/
//declaring nodes
struct node{
	double weights[n_layers][n_nodes][n_nodes];
	int features[n_layers][n_nodes];
	int bias;
};

//function to init data, i.e features and labels.
void generate_data(){
	//we are gonna have a 10X100 matrix,where each row corresponds 
	//to the laid out pixel vales and the corresponding labels for it.
}
void init_data(){
	//this is where we initialize the weights and the features array;

	// Initializing the weight matrix;
	for(int i=0;i<n_layers;i++){
		for(int j=0;j<n_nodes;j++){
			for(int k=0;k<n_nodes;k++){
				weights[i][j][k] = rand() % 1;
			}
		}
	}

	// Initializing the bias
	for(int i=0;i<n_layers;i++){
		bias[i] = rand() % 1;
	}

}
// Copy 1D array from 2D matrix
double* copy_row1D(int layer_no, int features[][]){
		for(int j=0;j<n_nodes;j++){
			copy_row[j] = features[layer_no][j];
		}
		//send the copied row for finding the dot product.
		return copy_row
	}

// Copy transformed 1D feature array into the 2D matrix.
void copy_row2D(int layer_no, int features[][]), int copy[]{
		for(int j=0;j<n_nodes;j++){
			features[layer_no][j] = copy[j];
		}
}
void find_dot_product(int feature_1D[], double weight[no_of_examples][no_of_neurons], double bias[]){
	//calculate WX + b
	double sum[];

	for(int i=0;i<n_layers;i++){
		double features_1D* = copy_row1D(i);
		for(int j=0;j<n_nodes;j++){
			for(int k=0;k<n_nodes;k++){
				sum[j] += feature_1D[j]*weight[i][j][k];
			}
			sum[j] = sum[j]+bias[j];
			feature_1D[j] = activation_function(sum[i]);
		}
		copy_row2D(feature_1D);
	}
}
double sigmoid(int x){
	//define the sigmoid function
	double temp;
	temp = 1/1+exp(-x)
	return temp;
}

double compute_cost(){
	//compute the cost: MSE

	int mse;
	for()
}
double sigmoid_derivative(double x){
	double temp;
	temp = sigmoid(x)*(1-sigmoid(x));
	return temp;
}

void main(){
	generate_data();
	init_data();
	find_dot_product();
	activation_function();
}