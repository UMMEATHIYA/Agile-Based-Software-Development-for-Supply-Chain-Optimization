#include <iostream>
#include <vector>
#include <cmath>

// Optimizing supply chain costs and delivery times
// Input: delivery_data (matrix with cost, delivery_time, distance)
// Output: optimized_results (matrix with optimized cost and delivery_time)

extern "C" {
    std::vector<std::vector<double>> optimize_supply_chain(const std::vector<std::vector<double>>& delivery_data) {
        // Create optimized results vector
        std::vector<std::vector<double>> optimized_results;

        for (auto& data : delivery_data) {
            double cost = data[0];  // Cost
            double delivery_time = data[1];  // Delivery Time
            double distance = data[2];  // Distance

            // Example optimization logic: reduce cost and delivery time based on distance
            cost *= 0.9;  // Reduce cost by 10%
            delivery_time *= 0.95;  // Reduce delivery time by 5%

            optimized_results.push_back({cost, delivery_time});
        }
        
        return optimized_results;
    }
}
