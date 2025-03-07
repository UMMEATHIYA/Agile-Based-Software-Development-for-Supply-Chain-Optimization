# This is a Cython wrapper for the C++ code
from libcpp.vector cimport vector

# Import the C++ function
cdef extern from "optimization_module.cpp":
    vector[vector[double]] optimize_supply_chain(vector[vector[double]] delivery_data)

# Function to call the C++ optimizer from Python
def optimize_supply_chain(delivery_data):
    # Convert the input data to C++ vector format
    cdef vector[vector[double]] c_data
    for row in delivery_data:
        cdef vector[double] c_row
        for item in row:
            c_row.push_back(item)
        c_data.push_back(c_row)
    
    # Call the C++ optimization function
    cdef vector[vector[double]] result = optimize_supply_chain(c_data)
    
    # Convert the result back to a Python list format
    result_python = [[item[0], item[1]] for item in result]
    return result_python
