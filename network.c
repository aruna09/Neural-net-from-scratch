#include <stdio.h>
#include <stdlib.h>
#include <math.h> //gcc -o net net.c -lm to link math library
#define no_of_nodes 10
#define no_of_layers 5 

typedef struct 
{
	int x;
	double weights[no_of_nodes];
	double weight_last_layer;
}n ;

//used to initialize the network with the no of layers and nodes.
void init_network(/*pass and return structure objects here*/){
	/*
	If there are 6 layers(5(ip) + 1(op)) we need 4 weight vectors.
	No weight vector for the last but one layer as it is connected to
	only one neuron.
	*/
	n nodes[no_of_layers-1][no_of_nodes];
}

//function to initialize bias and weight values
void initialize_values(n node_struct){

	/*
	Issue:
	1. With how you pass a matrix of structures. 
		Once corrected add code here.
	2. Initialize x[] values for all layers by reading from training set

	initialize_values(nodes);
	*/

	int i, j, k;
	
	for(i=0;i<no_of_nodes;i++)
		nodes[0][i].x = 1;//2

	//initializing the bias.
	for(i=0;i<no_of_layers-2;i++)
		bias[i] = rand() % 10;

	//initializing the weights
	for(i=0;i<no_of_layers-1;i++){
		for(j=0;j<no_of_nodes;j++){
			for(k=0;k<no_of_nodes;k++){
				nodes[i][j].weights[j] = rand() % 1;
			}
		}
	}
	
}

//sample function to perform activation
double sigmoid(double x){
	return(1/1+exp(-x));
}

//function to computer derivative to compute cost
doub sigmoid_derivative(double x){
	return(sigmoid(x) * (1-sigmoid(x)));
}


void dot_product(){
	/*
	figure out a way to pass structures, until then 
	the function defination is in the main()
	*/
	double sum[no_of_layers][no_of_nodes];


	//compute the dot product: x.w + b;
	for(i=0;i<no_of_layers;i++){
		for(j=0;j<no_of_nodes;j++){
			for(k=0;k<no_of_nodes;k++){
				sum[i][k] += nodes[i][j].x * nodes[i][j].weights[k];
			}
		}
		for(a=0;a<no_of_nodes;a++){
			sum[i][a] = sum[i][a]+bias[i];
			sum[i][a] = sigmoid(sum[i][a]);
			nodes[i][a].x = sum[i][a];
		}
	}

}

//function to compute the error
double* cost_function(double predicted[], int label[], int l){
	//computing the MSE
	double error[l];
	//size of predicted and label is same. let that be l.
	for(i=0;i<l;i++){
		error[i] = pow(predicted[i]-label[i], 2);
	}
	//returning an array. correct the type.
	return error;	
}

void feed_forward(){
	dot_product();
}

void back_prop(){
	double sum;
	/*
	bias for the last layer.
	assuming that I am working wth the last but one layer.
	have to call this for all examples in training data.
	*/
	double bias = rand() % 2;
	int index;//index no of the training data
		for(j=0;j<no_of_nodes;j++){
			sum += (nodes[no_of_layers-1][j].x * nodes[no_of_layers-1][j].weight_last_layer) + bias;
			dpred_dz[i] = sigmoid_der(sum);
		}
		predicted[index] = sigmoid(sum);
		//call this only after all the training examples are done.
		//predicted and label are two arrays and error function computes th error value
		//for each prediction. Error is also an array
		error = cost_function(predicted, label);
		
		for(i=0;i<length_of_error;i++){
			delta[i] = error[i] * dpred_dz[i];
		}
		

		//transposing the input x to multiply
		double learning_rate = 0.5;//change this.
		for(i=0;i<no_of_layers;i++){
			for(j=0;j<no_of_nodes;j++){
				matrix_transpose[j][i] = nodes[i][j].weights[j];
				nodes[i][j].weights[j] -= learning_rate * matrix_transpose[j][i] * delta[j];
			}
		}

}
void main(){
	/*
	Ask the user for the number of layers and the nodes in each layer.
	This net is custom made to be a fully connected neural net with the
	same number of nodes in each layer.

	Pass the required parameters to init_function(no_of_layer, no_of_nodes)
	*/


	//function to call the dot_product function.
	// The defination above is dot_product's.
	for(i=0;i<200;i++){
		feed_forward();
		back_prop();
	}
}