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
	double weights[no_of_examples][no_of_neurons];
	int features[no_of_examples][no_of_neurons];
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
	for(int i=0;i<no_neurons;i++){
		for(int j=0;j<no_pixels;j++){
			weights[i][j] = rand() % 1;
		}
	}

	// Initializing the bias
	for(int i=0;i<no_of_layers;i++){
		bias[i] = rand() % 1;
	}

}
// Copy 1D array from 2D matrix
void copy_row1D(int features[][]){
	for(int i=0;i<no_of_examples;i++){
		for(int j=0;j<no_of_neurons;j++){
			copy_row[j] = features[i][j];
		}
		//send the copied row for finding the dot product.
		find_dot_product(copy_row, weights, bias);
	}
}

// Copy transformed 1D feature array into the 2D matrix.
void copy_row2D(int features[][]), int copy[]{
	for(int i=0;i<no_of_examples;i++){
		for(int j=0;j<no_of_neurons;j++){
			features[i][j] = copy[j];
		}
	}
}
void find_dot_product(int feature_1D[], double weight[no_of_examples][no_of_neurons], double bias[]){
	//calculate WX + b
	double sum;

	for(int i=0;i<no_of_examples;i++){
		for(int j=0;j<no_of_neurons;j++){
			sum += feature_1D[i]*weight[i][j];
		}
		sum = sum+bias[i];
		feature_1D[i] = activation_function(sum);
	}
	copy_row2D(feature_1D);
}
double activation_function(int x){
	//define the sigmoid function
	double temp;
	temp = 1/1+exp(-x)
	return temp;
}

void main(){
	generate_data();
	init_data();
	find_dot_product();
	activation_function();
}