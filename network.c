#include <stdio.h>
#include <stdlib.h>
#include <math.h> //gcc -o net net.c -lm to link math library
#define no_of_nodes 10
#define no_of_layers 5 
#define size_of_training_set 1000

typedef struct 
{
	int x;
	double weights[no_of_nodes];
	double weight_last_layer[10];
}n ;

	/*

	Used to initialize the network with the no of layers and nodes.
	If there are 6 layers(5(ip) + 1(op)) we need 4 weight vectors.
	No weight vector for the last but one layer as it is connected to
	only ten neuron. The weight array will be assigned separately.

	*/
	n nodes[no_of_layers-1][no_of_nodes];
	double sum[no_of_layers][no_of_nodes];
	double error[size_of_training_set];
	double predicted[size_of_training_set];
	int label[size_of_training_set];//read from training set
	double bias_last_layer;
	int index;//for recording the predicted value for each sample
	double learning_rate = 0.5;//change this.

void initialize_values(n node_struct){

	/*
	
	Function to initialize bias and weight values.

	Issue:
	1. Initialize x[] values for all layers by reading from training set

	Initialize_values
	Initializing the bias.
	Initializing the weights
	
	*/

	int i, j, k;
	
	for(i = 0; i < no_of_nodes; i++)
		nodes[0][i].x = 1;

	for(i = 0; i < no_of_layers-2; i++)
		bias[i] = rand() % 10;

	for(i = 0; i < no_of_layers-1; i++){
		for(j = 0; j < no_of_nodes; j++){
			for(k = 0; k < no_of_nodes; k++){
				nodes[i][j].weights[j] = rand() % 1;
			}
		}
	}
	
}


double sigmoid(double x){

	/*

	Sample function to perform activation

	*/
	return(1/1+exp(-x));
}


double sigmoid_derivative(double x){
	/*

	Function to computer derivative to compute cost.

	*/

	return(sigmoid(x) * (1-sigmoid(x)));
}


void dot_product(){


	/*

	Function to compute the dot product: W.X + b

	*/
	for(i = 0; i < no_of_layers; i++){
		for(j = 0; j < no_of_nodes; j++){
			for(k = 0; k < no_of_nodes; k++){
				sum[i][k] += nodes[i][j].x * nodes[i][j].weights[k];
			}
		}
		for(a = 0; a < no_of_nodes; a++){
			sum[i][a] = sum[i][a] + bias[i];
			sum[i][a] = sigmoid(sum[i][a]);
			nodes[i][a].x = sum[i][a];
		}
	}

}


double cost_function(double predicted, double label){

	/*

	Function to compute the error.
	Computing MSE

	*/

	error = pow(predicted-label, 2);
	
	return error;	
}

void feed_forward(){

	/*

	Function to carry out forward propagation.
	 Calls dot_product to do the needful.

	*/

	dot_product();
}

void back_prop(){
	/*

	Function to carry out backward propagation.
	Calls dot_product to do the needful.

	*/

	int j;
	/*

	Bias for the last layer.
	Assuming that I am working wth the last but one layer.

	*/
	
	
		for(j = 0; j < no_of_nodes; j++){
			for(k = 0; k < 10; k++){
				sum += (nodes[no_of_layers-1][j].x * nodes[no_of_layers-1][j].weight_last_layer[k]) + bias_last_layer;
				nodes[no_of_layers][k].x += sum;
				dpred_dz[k] = sigmoid_der(sum);
			}
		}

		/*

		Assuming that after each forward prop for a particular 
		training sample, backword prop takes place, which essentially 
		means that error is not an array. It is a single double value.

		*/
		int i;//index for mapping the labels

		for(j = 0; j < 10; j++){
			predicted[j] = sigmoid(nodes[no_of_layers-1][j].x);
			/* 

			Here a sigmoid layer is being used. i.e with 10 neurons in 
			the last layer, the output would be an array of 0's and 1's
			where the corresponding index to a 1 will be the respective number 

			*/

			// somevalue is the threshold value for node to get activated.
			if(predicted[j] > somevalue){
				number  = j;
				/*

				do something with label, label has been initialized as an 
				array but taking it as a number sounds more logical.
				something like label[i]

				*/
				error = cost_function(number, label[i]);
			}
			i++;
		}
		
		for(i = 0; i < size_of_training_set; i++){
			delta[i] = error[i] * dpred_dz[i];
		}
		
		
		for(i = 0; i < no_of_layers; i++){
			for(j = 0; j < no_of_nodes; j++){
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


	/*

	For each training sample run the forward and back prop atleast 200 times.
	That's the reason as rk why we 

	*/

	for(i=0;i<size_of_training_set;i++){
		feed_forward();
		back_prop();
	}
}