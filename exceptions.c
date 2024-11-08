#include "stm32f4xx.h"

// Function prototypes
void HardFault_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void PendSV_Handler(void);
void SVC_Handler(void);

void triggerHardFault(void);
void triggerBusFault(void);
void triggerUsageFault(void);
void triggerPendSV(void);
void triggerSVCall(void);
void initializeSystem(void);
void toggleLED(void);

// Assuming an LED is connected to pin PC13
#define LED_PIN 13

// Main function
int main(void) {
    // Initialize system (e.g., configure clocks, peripherals)
    initializeSystem();

    // Infinite loop
    while (1) {
        // Uncomment one of the following lines to test specific faults
        //triggerHardFault();
        triggerBusFault();
        //triggerUsageFault();
        //triggerPendSV();
        //triggerSVCall();  // Uncomment to trigger an SVC Fault
    }
}

// Function to trigger a Hard Fault by division by zero
void triggerHardFault(void) {
    volatile int divisor = 0;
    volatile int result = 10 / divisor; // Division by zero to trigger Hard Fault
    (void)result;
}

// Function to trigger a Bus Fault
void triggerBusFault(void) {
    // Enable Bus Fault handler
    SCB->SHCSR |= SCB_SHCSR_BUSFAULTENA_Msk;
    
    // Access an invalid peripheral address to trigger a Bus Fault
    volatile int *pInvalidPeriphAddress = (int *)0x60000000; // Invalid peripheral address
    *pInvalidPeriphAddress = 0; // Write to invalid peripheral space
}

// Function to trigger a Usage Fault
void triggerUsageFault(void) {
    // Enable Usage Fault and Divide-by-Zero trap
    SCB->CCR |= SCB_CCR_DIV_0_TRP_Msk; // Set the DIV_0_TRP bit to trap divide-by-zero errors
    
    // Perform a divide-by-zero operation to trigger the Usage Fault
    volatile int numerator = 10;
    volatile int divisor = 0;
    volatile int result = numerator / divisor; // This will now trigger a Usage Fault

    (void)result; // Prevent unused variable warning
}

// Function to trigger a PendSV Fault
void triggerPendSV(void) {
    // Set PendSV interrupt pending to trigger PendSV_Handler
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

// Function to trigger an SVC (Supervisor Call) Fault
void triggerSVCall(void) {
    __asm("SVC #0"); // Supervisor call to trigger SVC_Handler
}

// Hard Fault Handler
void HardFault_Handler(void) {
    while (1) {
        toggleLED(); // Toggle LED to indicate Hard Fault
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}

// Bus Fault Handler
void BusFault_Handler(void) {
    while (1) {
        toggleLED(); // Toggle LED to indicate Bus Fault
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}

// Usage Fault Handler
void UsageFault_Handler(void) {
    while (1) {
        toggleLED(); // Toggle LED to indicate Usage Fault
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}

// SVCall Handler
void SVC_Handler(void) {
    while (1) {
        toggleLED(); // Toggle LED to indicate SVC Call
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}

// PendSV Handler
void PendSV_Handler(void) {
    while (1) {
        toggleLED(); // Toggle LED to indicate PendSV
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}

// SysTick Handler (for periodic interrupts)
void SysTick_Handler(void) {
    toggleLED(); // Toggle LED to indicate SysTick interrupt
}

// Example system initialization function
void initializeSystem(void) {
    // Enable the GPIO clock for port C
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Configure PC13 as output (LED)
    GPIOC->MODER |= (1 << (LED_PIN * 2)); // Set mode to output
}

// Function to toggle the LED
void toggleLED(void) {
    GPIOC->ODR ^= (1 << LED_PIN); // Toggle PC13
}
