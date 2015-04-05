################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/basic_communication.cpp \
../src/client.cpp \
../src/client_args.cpp \
../src/client_communication_handle.cpp 

OBJS += \
./src/basic_communication.o \
./src/client.o \
./src/client_args.o \
./src/client_communication_handle.o 

CPP_DEPS += \
./src/basic_communication.d \
./src/client.d \
./src/client_args.d \
./src/client_communication_handle.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -lpthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


