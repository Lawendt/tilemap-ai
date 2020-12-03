#pragma once
#include <fann.h>
#include <fann_cpp.h>
#include <string>
#include <fann_data.h>
using namespace std;


class NNInterface
{
public:
	NNInterface();
	~NNInterface();

	void trainWithData(string txt);
	float * run(float *data);

	float learning_rate;
	unsigned int num_layers;
	unsigned int num_input;
	unsigned int num_hidden;
	unsigned int num_output;
	float desired_error;
	unsigned int max_iterations;
	unsigned int iterations_between_reports;

	FANN::neural_net net;


};

