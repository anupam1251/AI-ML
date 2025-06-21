#include <iostream>
#include <torch/torch.h>

int main() {
	torch::Tensor t = torch::tensor(8);
	std::cout << t << std::endl;
}