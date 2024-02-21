#include <iostream>
#include <vector>

// Function to calculate the moving average of a given vector
double calculateMovingAverage(const std::vector<double>& prices, int period) {
    double sum = 0;
    int count = 0;
    for (int i = prices.size() - period; i < prices.size(); i++) {
        sum += prices[i];
        count++;
    }
    return sum / count;
}

// Function to generate buy or sell signals based on the moving average crossover strategy
std::string generateSignal(const std::vector<double>& prices) {
    int period1 = 50; // Short-term moving average period
    int period2 = 200; // Long-term moving average period

    double shortTermMA = calculateMovingAverage(prices, period1);
    double longTermMA = calculateMovingAverage(prices, period2);

    if (shortTermMA > longTermMA) {
        return "Buy";
    } else {
        return "Sell";
    }
}

int main() {
    // Example usage
    std::vector<double> priceData = {100.5, 102.3, 99.8, 101.2, 103.5, 105.1, 104.7, 106.2, 107.8, 109.4};
    std::string signal = generateSignal(priceData);
    std::cout << "Signal: " << signal << std::endl;

    return 0;
}
