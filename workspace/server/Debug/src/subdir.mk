################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server.cpp \
../src/server_args.cpp \
../src/server_host_handle.cpp \
../src/server_initializer.cpp 

OBJS += \
./src/server.o \
./src/server_args.o \
./src/server_host_handle.o \
./src/server_initializer.o 

CPP_DEPS += \
./src/server.d \
./src/server_args.d \
./src/server_host_handle.d \
./src/server_initializer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


