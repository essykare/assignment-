#!/bin/bash

# Prompt the user to enter employee name, hours worked, and rate per hour
read -p "Enter employee name: " employee_name
read -p "Enter hours worked: " hours_worked
read -p "Enter rate per hour: " rate_per_hour

# Calculate basic pay
basic_pay=$((hours_worked * rate_per_hour))

# Calculate tax based on basic pay
if [ $basic_pay -gt 70000 ]; then
    tax=$((basic_pay * 25 / 100))
elif [ $basic_pay -ge 15000 ]; then
    tax=$((basic_pay * 15 / 100))
else
    tax=0
fi

# Calculate net pay
net_pay=$((basic_pay - tax))

# Display results
echo "Employee Name: $employee_name"
echo "Basic Pay: $basic_pay"
echo "Tax: $tax"
echo "Net Pay: $net_pay"
