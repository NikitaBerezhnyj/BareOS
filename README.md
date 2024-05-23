# BareOS

BareOS repository has [Ukrainian :ukraine:](#bareos-ukraine) and [English :uk:](#bareos-uk) localizations

## BareOS :ukraine:

<p align='center'>
  <img src='./icon.png' alt='BareOS icon' style="width:50%">
</p>

**_Швидкий перехід по розділам_**

- [BareOS](#bareos)
  - [BareOS :ukraine:](#bareos-ukraine)
    - [Про проект](#про-проект)
    - [Вимоги](#вимоги)
    - [Інструкції з використання](#інструкції-з-використання)
  - [BareOS :uk:](#bareos-uk)
    - [About](#about)
    - [Requirements](#requirements)
    - [Usage](#usage)

### Про проект

Цей проект є простим ядром операційної системи, призначеним для роботи на архітектурі x86. Ядро написане на комбінації мов програмування Асемблера та C, що забезпечує практичний досвід навчання низькорівневому системному програмуванню та проектуванню завантажувача.

Основна мета цього проекту - слугувати освітнім ресурсом для розуміння внутрішньої роботи ядра операційної системи. Він пропонує міцну основу для вивчення таких тем, як управління пам'яттю, обробка переривань та взаємодія з апаратним забезпеченням на низькому рівні.

### Вимоги

Цей проект спирається на наступні залежності:

- **_NASM (Netwide Assembler)_** версії 2.16.03 або новішої. Популярний компілятор асемблера, який використовується для компіляції асемблерного коду в об'єктні файли.
- **_GCC (GNU Compiler Collection)_** версії 13.2.1 або новішої. Широковживаний компілятор C для компіляції вихідного коду C в об'єктні файли.
- **_GRUB (Великий уніфікований завантажувач)_** версії 2.12-3 або новішої. Зокрема, утиліта grub-mkrescue необхідна для створення завантажувального ISO-образу зі скомпільованого ядра та інших файлів.
- **_xorriso_** версії 1.5.6 або новішої. Інструмент для створення, маніпулювання та запису образів файлової системи ISO 9660 з розширеннями Rock Ridge та Joliet.
- **_QEMU emulator_** версії 8.2.2 або новішої. Популярний емулятор машин з відкритим вихідним кодом і віртуалізатор, який використовується для запуску і тестування скомпільованого ядра у віртуальному середовищі.

### Інструкції з використання

Щоб запустити операційну систему, вам потрібно виконати наступні кроки:

1. Клонувати репозиторій на свій комп'ютер.

```bash
git clone https://github.com/NikitaBerezhnyj/BareOS.git
```

2. Запустіть команду для збірки проекту.

```bash
make compile
```

3. Запустіть команду для запуску скомпільованого ядра у емуляторі qemu.

```bash
make run
```

## BareOS :uk:

<p align='center'>
  <img src='./icon.png' alt='BareOS icon' style="width:50%">
</p>

**_Quick transition between sections:_**

- [BareOS](#bareos)
  - [BareOS :ukraine:](#bareos-ukraine)
    - [Про проект](#про-проект)
    - [Вимоги](#вимоги)
    - [Інструкції з використання](#інструкції-з-використання)
  - [BareOS :uk:](#bareos-uk)
    - [About](#about)
    - [Requirements](#requirements)
    - [Usage](#usage)

### About

This project is a simple operating system kernel designed to run on x86 architecture. The kernel is written in a combination of Assembly and C programming languages, providing a hands-on learning experience in low-level system programming and bootloader design.

The primary goal of this project is to serve as an educational resource for understanding the inner workings of an operating system kernel. It offers a solid foundation for exploring topics such as memory management, interrupt handling, and hardware interaction at a low level.

### Requirements

This project relies on the following dependencies:

- **_NASM (Netwide Assembler)_** version 2.16.03 or later. A popular assembler compiler used to compile the assembly code into object files.
- **_GCC (GNU Compiler Collection)_** version 13.2.1 or later. A widely-used C compiler for compiling the C source code into object files.
- **_GRUB (GRand Unified Bootloader)_** version 2.12-3 or later. Specifically, the grub-mkrescue utility is required for creating a bootable ISO image from the compiled kernel and other files.
- **_xorriso_** version 1.5.6 or later. A tool for creating, manipulating, and writing ISO 9660 filesystem images with extensions like Rock Ridge and Joliet.
- **_QEMU emulator_** version 8.2.2 or later. A popular open-source machine emulator and virtualizer used for running and testing the compiled kernel in a virtual environment.

### Usage

To use the compiler, you need to perform the following steps:

1. Clone the repository to your computer.

```bash
git clone https://github.com/NikitaBerezhnyj/BareOS.git
```

2. Run the command to build the project.

```bash
make compile
```

3. Run the command to run the compiled kernel in the qemu emulator.

```bash
make run
```
