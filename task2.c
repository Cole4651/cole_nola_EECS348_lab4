#include <stdio.h>

static const char *scale_name(int scale)
{
	if (scale == 1) {
		return "Fahrenheit";
	}
	if (scale == 2) {
		return "Celsius";
	}
	return "Kelvin";
}

static double to_celsius(double temperature, int scale)
{
	if (scale == 1) {
		return (temperature - 32.0) * 5.0 / 9.0;
	}
	if (scale == 3) {
		return temperature - 273.15;
	}
	return temperature;
}

static double from_celsius(double temperature, int scale)
{
	if (scale == 1) {
		return temperature * 9.0 / 5.0 + 32.0;
	}
	if (scale == 3) {
		return temperature + 273.15;
	}
	return temperature;
}

static const char *temperature_category(double celsius)
{
	if (celsius < 0.0) {
		return "Freezing";
	}
	if (celsius < 10.0) {
		return "Cold";
	}
	if (celsius < 25.0) {
		return "Comfortable";
	}
	if (celsius < 35.0) {
		return "Hot";
	}
	return "Extreme Heat";
}

static const char *weather_advisory(double celsius)
{
	if (celsius < 0.0) {
		return "Wear a heavy jacket.";
	}
	if (celsius < 10.0) {
		return "Wear a jacket.";
	}
	if (celsius < 25.0) {
		return "The weather is comfortable.";
	}
	if (celsius < 35.0) {
		return "Stay hydrated and wear light clothing.";
	}
	return "Stay indoors if possible and stay hydrated.";
}

int main(void)
{
	double input_temperature;
	double celsius_temperature;
	double converted_temperature;
	int input_scale;
	int target_scale;

	printf("Enter the temperature value: ");
	if (scanf("%lf", &input_temperature) != 1) {
		printf("Please enter a valid temperature.\n");
		return 1;
	}

	printf("Choose the input scale:\n");
	printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
	printf("Enter your choice: ");
	if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
		printf("Please choose 1, 2, or 3.\n");
		return 1;
	}

	if (input_scale == 3 && input_temperature < 0.0) {
		printf("Kelvin temperatures cannot be negative.\n");
		return 1;
	}

	printf("Choose the conversion target:\n");
	printf("1. Fahrenheit\n2. Celsius\n3. Kelvin\n");
	printf("Enter your choice: ");
	if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
		printf("Please choose 1, 2, or 3.\n");
		return 1;
	}

	celsius_temperature = to_celsius(input_temperature, input_scale);
	converted_temperature = from_celsius(celsius_temperature, target_scale);

	printf("Converted temperature: %.2f %s\n", converted_temperature,
		   scale_name(target_scale));
	printf("Category: %s\n", temperature_category(celsius_temperature));
	printf("Advisory: %s\n", weather_advisory(celsius_temperature));

	return 0;
}
