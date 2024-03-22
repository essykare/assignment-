#!/bin/bash

# Prompt the user to enter CustomerID, CustomerName, and UnitConsumed
read -p "Enter CustomerID: " customer_id
read -p "Enter CustomerName: " customer_name
read -p "Enter UnitConsumed: " unit_consumed

# Initialize total bill variable
total_bill=0

# Calculate charges based on units consumed
if [ $unit_consumed -lt 200 ]; then
    charges_per_unit=120
elif [ $unit_consumed -lt 400 ]; then
    charges_per_unit=150
elif [ $unit_consumed -lt 600 ]; then
    charges_per_unit=200
else
    charges_per_unit=250
fi

# Calculate total bill
total_bill=$((unit_consumed * charges_per_unit))

# Display results
echo "CustomerID: $customer_id"
echo "CustomerName: $customer_name"
echo "Units Consumed: $unit_consumed"
echo "Total Bill: $total_bill"
