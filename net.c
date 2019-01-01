#include <stdio.h>
#include <stdlib.h>
#include <math.h> //gcc -o net net.c -lm to link math library
#define no_of_nodes 10
#define hidden_layers 3

typedef struct 
{
	int x;
	double weights[no_of_nodes];
}n ;

//used to initialize the network with the no of layers and nodes.
void init_network(){
	
}

//function to initialize bias and weight values
void initialize_values(n node_struct){

	//issue with how you pass a matrix of structures. 
	//Once corrected add code here.
	
}

//sample function to perform activation
double sigmoid(double x){
	return(1/1+exp(-x));
}

//function to computer derivative to compute cost
double sigmoid_derivative(double x){
	return(sigmoid(x) * (1-sigmoid(x)));
}


void dot_product(){
	//figure out a way to pass structures, until then 
	//the function defination is in the main()

}
void main(){
	/*
	Ask the user for the number of layers and the nodes in each layer.
	This net is custom made to be a fully connected neural net with the
	same number of nodes in each layer.

	Pass the required parameters to init_function(no_of_layer, no_of_nodes)
	*/

	double bias[hidden_layers];
	n nodes[hidden_layers][no_of_nodes];
	//initialize_values(nodes);
	int i, j, k;
	for(i=0;i<hidden_layers;i++){

		//initalizing the bias for each layer
		bias[i] = rand() % 2;

		for(j=0;j<no_of_nodes;j++){

			//read this from the dataset
			nodes[i][j].x = 1;

			for(k=0;k<no_of_nodes;k++){

				//initalize the weights.
				nodes[i][j].weights[j] = rand() % 1;
			}
		}
	}

dot_product();
double sum[hidden_layers][no_of_nodes];
	//compute the dot product: x.w + b;
	for(i=0;i<hidden_layers;i++){
		for(j=0;j<no_of_nodes;j++){
			for(k=0;k<no_of_nodes;k++){
				sum[i][k] += nodes[i][j].x * nodes[i][j].weights[k];
			}
		}
	}
	for(i=0;i<hidden_layers;i++){
		for(j=0;j<no_of_nodes;j++){
			sum[i][j] = sum[i][j]+bias[i];
			sum[i][j] = sigmoid(sum[i][j]);
			nodes[i][j].x = sum[i][j];
		}
	}
	
}