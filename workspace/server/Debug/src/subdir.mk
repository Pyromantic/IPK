################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/basic_communication.cpp \
../src/server.cpp \
../src/server_args.cpp \
../src/server_host_handle.cpp \
../src/server_initializer.cpp \
../src/server_users_parser.cpp 

OBJS += \
./src/basic_communication.o \
./src/server.o \
./src/server_args.o \
./src/server_host_handle.o \
./src/server_initializer.o \
./src/server_users_parser.o 

CPP_DEPS += \
./src/basic_communication.d \
./src/server.d \
./src/server_args.d \
./src/server_host_handle.d \
./src/server_initializer.d \
./src/server_users_parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


