#include "NNInterface.h"



NNInterface::NNInterface()
{
	learning_rate = 0.7f;
	num_layers = 3;
	num_input = 8;
	num_hidden = 3;
	num_output = 16;
	desired_error = 0.001f;
	max_iterations = 300000;
	iterations_between_reports = 1000;

	net.create_standard(num_layers, num_input, num_hidden, num_output);

	net.set_learning_rate(learning_rate);

	net.randomize_weights(-0.1,0.1);

	net.set_activation_steepness_hidden(1.0);
	net.set_activation_steepness_output(1.0);

	net.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC_STEPWISE);
	net.set_activation_function_output(FANN::SIGMOID_SYMMETRIC_STEPWISE);

}


NNInterface::~NNInterface()
{
}

void NNInterface::trainWithData(string txt)
{
	FANN::training_data data;
	if (data.read_train_from_file(txt))
	{
		// Initialize and train the network with the data
		net.init_weights(data);
		net.train_on_data(data, max_iterations,
			iterations_between_reports, desired_error);
	}
}

float * NNInterface::run(float *data)
{
	return net.run(data);
}
