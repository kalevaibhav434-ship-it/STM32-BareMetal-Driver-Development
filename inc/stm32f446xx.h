/**
 * ******************************************************************************
 * @file           : stm32f446xx.h
 * @brief          : Device Header File for STM32F446xx Microcontroller.
 * Contains memory base addresses, peripheral base addresses,
 * register definitions structures, and peripheral macros.
 * @author         : vaibhav.kale
 * ******************************************************************************
 */



/* * ============================================================================
 * SECTION 0: INCLUDE GUARDS (FILE PROTECTION)
 * ============================================================================
 * Why do we need this?
 * If this header file is included multiple times across different .c files
 * (e.g., main.c, gpio.c, usart.c), the compiler will see duplicate structures
 * and macros, throwing a "redefinition error".
 * * These guards ensure the compiler processes this file exactly ONCE.
 */
#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

/* Standard C library header inclusions */
#include <stdint.h>  /* Provides exact-width integers like uint32_t, uint16_t */
#include <string.h>  /* Provides useful string handling functions if needed */

/*
 * GCC Compiler attribute macro for Weak functions
 */
#ifndef __weak
  #define __weak __attribute__((weak))
#endif


/**********************************START:Processor Specific Details **********************************/
/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0          ( (volatile uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (volatile uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (volatile uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (volatile uint32_t*)0xE000E10c )


/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((volatile uint32_t*)0XE000E180)
#define NVIC_ICER1			((volatile uint32_t*)0XE000E184)
#define NVIC_ICER2  		((volatile uint32_t*)0XE000E188)
#define NVIC_ICER3			((volatile uint32_t*)0XE000E18C)


/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR 	((volatile uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4


/*
 * macros for all the possible priority levels
 */
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15

/* * ============================================================================
 * SECTION 1: SYSTEM MEMORY BASE ADDRESSES
 * ============================================================================
 * These are the entry point addresses for the core internal memory blocks
 * as designated by the ARM Cortex-M4 and STMicroelectronics architecture.
 * The 'U' suffix forces the compiler to treat these constants as Unsigned Integers.
 */
#define FLASH_BASEADDR                  0x08000000U /* Base address of Main Flash Memory (where code lives) */
#define SRAM1_BASEADDR                  0x20000000U /* Base address of Main SRAM1 (112 KB of RAM for variables) */
#define SRAM2_BASEADDR                  0x2001C000U /* Base address of SRAM2 (16 KB auxiliary RAM block) */
#define ROM_BASEADDR                    0x1FFF0000U /* Base address of System Memory (ST Bootloader ROM code) */
#define SRAM                            SRAM1_BASEADDR /* Default generic alias for primary system RAM */


/* * ============================================================================
 * SECTION 2: BUS PERIPHERAL BASE ADDRESSES
 * ============================================================================
 * Microcontroller peripherals are grouped onto different internal communication buses
 * depending on speed requirements. Each bus has a starting hardware address.
 */
#define PERIPH_BASE                     0x40000000U /* Absolute base address of all hardware peripherals */

/* Main Bus Domains mapped out by adding offsets to the primary peripheral base */
#define APB1PERIPH_BASEADDR             PERIPH_BASE                 /* Advanced Peripheral Bus 1 (Low-speed bus)  */
#define APB2PERIPH_BASEADDR             (PERIPH_BASE + 0x00010000U) /* Advanced Peripheral Bus 2 (High-speed bus) */
#define AHB1PERIPH_BASEADDR             (PERIPH_BASE + 0x00020000U) /* Advanced High-performance Bus 1             */
#define AHB2PERIPH_BASEADDR             (PERIPH_BASE + 0x10000000U) /* Advanced High-performance Bus 2 (USB, Camera)*/


/* * ============================================================================
 * SECTION 3: AHB1 BUS PERIPHERAL BASE ADDRESSES (GPIO PORTS)
 * ============================================================================
 * Each GPIO Port is assigned a 1 KB block (0x0400 bytes) of memory space.
 * We calculate their precise addresses sequentially by adding offsets.
 */
#define GPIOA_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0000) /* GPIO Port A Base Address */
#define GPIOB_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0400) /* GPIO Port B Base Address */
#define GPIOC_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0800) /* GPIO Port C Base Address */
#define GPIOD_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0C00) /* GPIO Port D Base Address */
#define GPIOE_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x1000) /* GPIO Port E Base Address */
#define GPIOF_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x1400) /* GPIO Port F Base Address */
#define GPIOG_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x1800) /* GPIO Port G Base Address */
#define GPIOH_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x1C00) /* GPIO Port H Base Address */
#define GPIOI_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x2000) /* GPIO Port I Base Address */


/* * ============================================================================
 * SECTION 4: APB1 BUS PERIPHERAL BASE ADDRESSES
 * ============================================================================
 * Lower speed communication protocols hang on this bus domain.
 */
#define SPI2_BASEADDR                   (APB1PERIPH_BASEADDR + 0x3800) /* SPI2 Peripheral Base Address */
#define SPI3_BASEADDR                   (APB1PERIPH_BASEADDR + 0x3C00) /* SPI3 Peripheral Base Address */

#define USART2_BASEADDR                 (APB1PERIPH_BASEADDR + 0x4400) /* USART2 Peripheral Base Address */
#define USART3_BASEADDR                 (APB1PERIPH_BASEADDR + 0x4800) /* USART3 Peripheral Base Address */
#define UART4_BASEADDR                  (APB1PERIPH_BASEADDR + 0x4C00) /* UART4 Peripheral Base Address */
#define UART5_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5000) /* UART5 Peripheral Base Address */

#define I2C1_BASEADDR                   (APB1PERIPH_BASEADDR + 0x5400) /* I2C1 Peripheral Base Address */
#define I2C2_BASEADDR                   (APB1PERIPH_BASEADDR + 0x5800) /* I2C2 Peripheral Base Address */
#define I2C3_BASEADDR                   (APB1PERIPH_BASEADDR + 0x5C00) /* I2C3 Peripheral Base Address */


/* * ============================================================================
 * SECTION 5: APB2 BUS PERIPHERAL BASE ADDRESSES
 * ============================================================================
 * High speed communication and control protocols hang on this bus domain.
 */
#define USART1_BASEADDR                 (APB2PERIPH_BASEADDR + 0x1000) /* USART1 Peripheral Base Address */
#define USART6_BASEADDR                 (APB2PERIPH_BASEADDR + 0x1400) /* USART6 Peripheral Base Address (Fixed Bus Location!) */
#define SPI1_BASEADDR                   (APB2PERIPH_BASEADDR + 0x3000) /* SPI1 Peripheral Base Address */
#define SYSCFG_BASEADDR                 (APB2PERIPH_BASEADDR + 0x3800) /* System Configuration Controller Base Address */
#define EXTI_BASEADDR                   (APB2PERIPH_BASEADDR + 0x3C00) /* External Interrupt Controller Base Address */


/* * ============================================================================
 * SECTION 6: PERIPHERAL REGISTER STRUCTURE DEFINITIONS
 * ============================================================================
 * C structures read memory sequentially. Because every register inside our STM32F446
 * hardware is exactly 32 bits wide, a sequence of 'uint32_t' member fields maps
 * step-by-step to the exact register memory spacing.
 *
 * CRITICAL CONCEPT: The 'volatile' keyword.
 * This instructs the compiler optimizer: "The hardware can modify these locations at
 * any time, and my code changes must write directly to the hardware immediately."
 * Without 'volatile', the compiler might store register updates in a CPU cache register,
 * causing your bare-metal driver changes to be silently ignored!
 */

/**
 * @brief General Purpose I/O (GPIO) Register Layout Structure
 */
typedef struct
{
    volatile uint32_t MODER;    /* 0x00: GPIO port mode register                         */
    volatile uint32_t OTYPER;   /* 0x04: GPIO port output type register                  */
    volatile uint32_t OSPEEDR;  /* 0x08: GPIO port output speed register                 */
    volatile uint32_t PUPDR;    /* 0x0C: GPIO port pull-up/pull-down register            */
    volatile uint32_t IDR;      /* 0x10: GPIO port input data register                   */
    volatile uint32_t ODR;      /* 0x14: GPIO port output data register                  */
    volatile uint32_t BSRR;     /* 0x18: GPIO port bit set/reset register                */
    volatile uint32_t LCKR;     /* 0x1C: GPIO port configuration lock register           */
    volatile uint32_t AFR[2];   /* 0x20 - 0x24: Alternate function configuration array
                                   AFR[0] maps to AFRL (Low), AFR[1] maps to AFRH (High) */
} GPIO_RegDef_t;


/**
 * @brief Reset and Clock Control (RCC) Register Layout Structure
 * Note: Empty memory gaps between registers are explicitly filled using 'RESERVED'
 * fields to maintain exact hardware bit alignment offsets.
 */
typedef struct
{
    volatile uint32_t CR;            /* 0x00: RCC clock control register */
    volatile uint32_t PLLCFGR;       /* 0x04: RCC PLL configuration register */
    volatile uint32_t CFGR;          /* 0x08: RCC clock configuration register */
    volatile uint32_t CIR;           /* 0x0C: RCC clock interrupt register */
    volatile uint32_t AHB1RSTR;      /* 0x10: RCC AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR;      /* 0x14: RCC AHB2 peripheral reset register */
    volatile uint32_t AHB3RSTR;      /* 0x18: RCC AHB3 peripheral reset register */
    uint32_t          RESERVED0;     /* 0x1C: 4-byte padding block */
    volatile uint32_t APB1RSTR;      /* 0x20: RCC APB1 peripheral reset register */
    volatile uint32_t APB2RSTR;      /* 0x24: RCC APB2 peripheral reset register */
    uint32_t          RESERVED1[2];  /* 0x28 - 0x2C: 8-byte padding block */
    volatile uint32_t AHB1ENR;       /* 0x30: RCC AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR;       /* 0x34: RCC its AHB2 peripheral clock enable register */
    volatile uint32_t AHB3ENR;       /* 0x38: RCC AHB3 peripheral clock enable register */
    uint32_t          RESERVED2;     /* 0x3C: 4-byte padding block */
    volatile uint32_t APB1ENR;       /* 0x40: RCC APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR;       /* 0x44: RCC APB2 peripheral clock enable register */
    uint32_t          RESERVED3[2];  /* 0x48 - 0x4C: 8-byte padding block */
    volatile uint32_t AHB1LPENR;     /* 0x50: RCC AHB1 peripheral clock enable in low power mode */
    volatile uint32_t AHB2LPENR;     /* 0x54: RCC AHB2 peripheral clock enable in low power mode */
    volatile uint32_t AHB3LPENR;     /* 0x58: RCC AHB3 peripheral clock enable in low power mode */
    uint32_t          RESERVED4;     /* 0x5C: 4-byte padding block */
    volatile uint32_t APB1LPENR;     /* 0x60: RCC APB1 peripheral clock enable in low power mode */
    volatile uint32_t APB2LPENR;     /* 0x64: RCC APB2 peripheral clock enable in low power mode */
    uint32_t          RESERVED5[2];  /* 0x68 - 0x6C: 8-byte padding block */
    volatile uint32_t BDCR;          /* 0x70: RCC Backup domain control register */
    volatile uint32_t CSR;           /* 0x74: RCC clock control & status register */
    uint32_t          RESERVED6[2];  /* 0x78 - 0x7C: 8-byte padding block */
    volatile uint32_t SSCGR;         /* 0x80: RCC spread spectrum clock generation register */
    volatile uint32_t PLLI2SCFGR;    /* 0x84: RCC PLLI2S configuration register */
    volatile uint32_t PLLSAICFGR;    /* 0x88: RCC PLLSAI configuration register */
    volatile uint32_t DCKCFGR;       /* 0x8C: RCC Dedicated Clocks configuration register */
    volatile uint32_t CKGATENR;      /* 0x90: RCC Clocks Gated Enable Register */
    volatile uint32_t DCKCFGR2;      /* 0x94: RCC Dedicated Clocks configuration register 2 */
} RCC_TypeDef;



/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	 volatile uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	 volatile uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	 volatile uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	 volatile uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	 volatile uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	 volatile uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */

}EXTI_RegDef_t;



/*
 * peripheral register definition structure for SPI
 */
typedef struct
{
	volatile uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	volatile uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	volatile uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	volatile uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	volatile uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	volatile uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	volatile uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	volatile uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	volatile uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;



/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	volatile uint32_t MEMRMP;       /*!< Give a short description,                    Address offset: 0x00      */
	volatile uint32_t PMC;          /*!< TODO,     									  Address offset: 0x04      */
	volatile uint32_t EXTICR[4];    /*!< TODO , 									  Address offset: 0x08-0x14 */
	uint32_t      RESERVED1[2];  /*!< TODO          							  Reserved, 0x18-0x1C    	*/
	volatile uint32_t CMPCR;        /*!< TODO         								  Address offset: 0x20      */
	uint32_t      RESERVED2[2];  /*!<                                             Reserved, 0x24-0x28 	    */
	volatile uint32_t CFGR;         /*!< TODO                                         Address offset: 0x2C   	*/
} SYSCFG_RegDef_t;


/*
 * peripheral register definition structure for I2C
 */
typedef struct
{
	volatile uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
	volatile uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	volatile uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
	volatile uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
	volatile uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
	volatile uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
	volatile uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
    volatile uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
    volatile uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
    volatile uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;



/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	volatile uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
	volatile uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
	volatile uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
	volatile uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
	volatile uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
	volatile uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
	volatile uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
} USART_RegDef_t;

/* * ============================================================================
 * SECTION 7: PERIPHERAL INSTANCE MACROS (TYPECASTING ADDRESSES TO POINTERS)
 * ============================================================================
 * These macros take the raw numerical addresses defined in Section 3, 4, & 5,
 * and cast them into pointers pointing to our logical layout structures.
 * * Example: `((GPIO_Reg_Def_t*)GPIOA_BASEADDR)` tells the program:
 * "Treat address 0x40020000 as a pointer to a GPIO structure."
 * This allows you to perform operations like: `GPIOA->MODER = 0x01;`
 */
#define GPIOA           ((GPIO_RegDef_t*)GPIOA_BASEADDR) //TYPECASTING
#define GPIOB           ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC           ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD           ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE           ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF           ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG           ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH           ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI           ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC_BASE        (0x40023800UL)
#define RCC             ((RCC_TypeDef *) RCC_BASE)

#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


#define SPI1  				((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  				((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  				((SPI_RegDef_t*)SPI3_BASEADDR)


#define I2C1  				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  				((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1  			((USART1 _RegDef_t*)USART1 _BASEADDR)
#define USART2  			((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  			((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  				((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  				((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  			((USART_RegDef_t*)USART6_BASEADDR)


/*
 *  returns port code for given GPIOx base address
 */
/*
 * This macro returns a code( between 0 to 7) for a given GPIO base address(x)
 */
#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
								        (x == GPIOE)?4:\
								        (x == GPIOF)?5:\
								        (x == GPIOG)?6:\
								        (x == GPIOH)?7: \
								        (x == GPIOI)?8:0)


/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 */

#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4
#define IRQ_NO_I2C1_EV     31
#define IRQ_NO_I2C1_ER     32
#define IRQ_NO_USART1	    37
#define IRQ_NO_USART2	    38
#define IRQ_NO_USART3	    39
#define IRQ_NO_UART4	    52
#define IRQ_NO_UART5	    53
#define IRQ_NO_USART6	    71
/* * ============================================================================
 * SECTION 8: CLOCK ENABLE BITWISE FUNCTIONAL MACROS
 * ============================================================================
 * Before using any peripheral, its internal clock must be enabled via the RCC block.
 * * Mechanics:
 * - `|=` (Bitwise OR assignment) keeps existing bits exactly the same while modifying only one target bit.
 * - `(1 << X)` shifts a binary '1' to position X to isolate the correct configuration channel.
 */

/* Clock Enable Macros for GPIO Ports (AHB1 Bus Domain) */
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1 << 0))  /* Enable Port A clock (Bit 0) */
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1 << 1))  /* Enable Port B clock (Bit 1) */
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1 << 2))  /* Enable Port C clock (Bit 2) */
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1 << 3))  /* Enable Port D clock (Bit 3) */
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1 << 4))  /* Enable Port E clock (Bit 4) */
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1 << 5))  /* Enable Port F clock (Bit 5) */
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1 << 6))  /* Enable Port G clock (Bit 6) */
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1 << 7))  /* Enable Port H clock (Bit 7) */
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |= (1 << 8))  /* Enable Port I clock (Bit 8) */

/* Clock Enable Macros for I2C Peripherals (APB1 Bus Domain) */
#define I2C1_PCLK_EN()      (RCC->APB1ENR |= (1 << 21)) /* Enable I2C1 clock (Bit 21) */
#define I2C2_PCLK_EN()      (RCC->APB1ENR |= (1 << 22)) /* Enable I2C2 clock (Bit 22) */
#define I2C3_PCLK_EN()      (RCC->APB1ENR |= (1 << 23)) /* Enable I2C3 clock (Bit 23) */

/* Clock Enable Macros for SPI Peripherals (Shared Bus Domains) */
#define SPI1_PCLK_EN()      (RCC->APB2ENR |= (1 << 12)) /* Enable SPI1 clock (APB2 Bit 12) */
#define SPI2_PCLK_EN()      (RCC->APB1ENR |= (1 << 14)) /* Enable SPI2 clock (APB1 Bit 14) */
#define SPI3_PCLK_EN()      (RCC->APB1ENR |= (1 << 15)) /* Enable SPI3 clock (APB1 Bit 15) */
#define SPI4_PCLK_EN() 		(RCC->APB2ENR |= (1 << 13))

/* Clock Enable Macros for Communication Lines (USART/UART) */
#define USART1_PCLK_EN()    (RCC->APB2ENR |= (1 << 4))  /* Enable USART1 clock (APB2 Bit 4)  */
#define USART2_PCLK_EN()    (RCC->APB1ENR |= (1 << 17)) /* Enable USART2 clock (APB1 Bit 17) */
#define USART3_PCLK_EN()    (RCC->APB1ENR |= (1 << 18)) /* Enable USART3 clock (APB1 Bit 18) */
#define UART4_PCLK_EN()     (RCC->APB1ENR |= (1 << 19)) /* Enable UART4 clock (APB1 Bit 19)  */
#define UART5_PCLK_EN()     (RCC->APB1ENR |= (1 << 20)) /* Enable UART5 clock (APB1 Bit 20)  */
#define USART6_PCLK_EN()    (RCC->APB2ENR |= (1 << 5))  /* Enable USART6 clock (APB2 Bit 5 - Corrected!) */

/* Clock Enable Macros for System Configuration System */
#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1 << 14)) /* Enable SYSCFG clock (APB2 Bit 14) */



//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET         RESET
#define FLAG_SET 			SET


/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_FRF						4
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7
#define SPI_SR_FRE					 	8



/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_OAR1
 */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15


/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15


/*
 *  Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)







#endif /* INC_STM32F446XX_H_ */

