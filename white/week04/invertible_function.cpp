// #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
}; */

class FunctionPart {
	public:
		FunctionPart(const char& new_operation, const double& new_value) {
			operation = new_operation;
			value = new_value;
		}

		double Apply(double source_value) const {
			if (operation == '+') {
				return source_value + value;
			} else {
				return source_value - value;
			}
		}

		void Invert() {
			operation = (operation == '+') ? '-' : '+';
		}

	private:
		char operation;
		double value;
};

class Function {
	public:
		void AddPart(char operation, double value) {
			parts.push_back({operation, value});
		}

		double Apply(double value) const {
			for (const auto& part : parts) {
				value = part.Apply(value);
			}
			return value;
		}

		void Invert() {
			for (auto& part : parts) {
				part.Invert();
			}
			reverse(parts.begin(), parts.end());
		}

	private:
		vector<FunctionPart> parts;
};

/* Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 46) << endl;
  return 0;
} */
