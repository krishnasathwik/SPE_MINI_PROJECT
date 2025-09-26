# Base image
FROM ubuntu:22.04

# Install necessary packages
RUN apt-get update && apt-get install -y g++ python3 python3-pip make

# Set working directory inside container
WORKDIR /app

# Copy project files into container
COPY . .

# Build the C++ calculator
RUN make all

# Default command to run the calculator
CMD ["./calc"]
