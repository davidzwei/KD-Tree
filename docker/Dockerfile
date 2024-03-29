# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Set environment variable to avoid interactive input
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists and install necessary packages
RUN apt-get update && \
    apt-get install -y \
    python3 \
    python3-pip \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Install pybind11
RUN pip3 install pybind11

# Install pytest
RUN pip3 install pytest

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# If there are additional dependencies, they can be installed here

# Define the default command or entry point
CMD ["bash"]