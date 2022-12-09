#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_icent);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an elf file
 * @e_ident: A pointer to arry 
 * if the fileis not elf file exit
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'L')
		{
			dprintf(STDERR_FILENO, "Error not an elf file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - prints the magic numbers
 * @e_ident: A pointer to arry
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf ("magic number");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf ("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf ("\n");
		else
			printf ("");
	}
}

/**
 * print_class - prints the class of an elf
 * @e_ident: A pointer to arry
 */
void print_class(unsigned char *e_ident)
{
	printf("class:");
		switch (e_ident [EI_CLASS])
		{
			case ELFCLASSNONE:
				printf ("none\n");
				break;
			case ELFCLASS32:
				printf ("elf32\n");
				break;
			case ELFCLASS64:
				printf ("elf64\n");
				break;
			default:
				printf ("unknown: %x>\n", e_ident[EI_CLASS]);
		}
}

/**
 * print_data - prints the data of elf
 * @e_ident: A pointer to arry
 */
void print_data(unsigned char *e_ident)
{
	printf("data:");
		switch (e_ident [EI_DATA])
		{
			case ELFDATANONE:
				printf ("none\n");
				break;
			case ELFDATA2LSB:
				printf ("2's complement, littel indean\n");
				break;
			case ELFDATA2MSB:
				printf ("2's complement,big indean\n");
				break;
			default:
				printf ("unknown: %x>\n", e_ident[EI_CLASS]);
		}
}

/**
 * print_version - prints the version of an elf
 * @e_ident: A pointer to arry
 */
void print_version(unsigned char *e_ident)
{
	printf ("version"
		e_ident[EI_VERSION]);
		switch (e_ident[EI_VERSION])
		{
			case EV_CURRENT:
				printf ("current\n");
				break;
			default:
				printf ("\n");
				break;
		}
}

/**
 * print_osabi - prints the os/abi on elf header
 * @e_ident: A pointer to arry
 */
void print_osabi(unsigned char *e_ident)
{
	printf ("os/abi");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("unix systemv \n");
			break;
		case ELFOSABI_HPUX:
			printf("unix hp ux \n");
			break;
		case ELFOSABI_NETBSD:
			printf("unix netbsd \n");
			break;
		case ELFOSABI_linux:
			printf("linux\n");
			break;
		case ELFOSABI_SOLARIX:
			printf("solaris\n");
			break;
		default:
			printf("unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints abi version
 * @e_ident: A pointer to arry
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI VERSION:         %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * pritn_type - prints the type of an elf
 * @e_ident: A pointer to arry
 * @e_type: the elf type
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 0;

	printf("type:                            ");

	swich (e_type)
	{
		case ET_NONE:
			printf("nonr (none)\n");
			break;
			 case ET_REL:
			printf("REL (relocatablefile)\n");
			break;
			 case ET_EXEC:
			printf("REL (executablefile)\n");
			break;
			 case ET_DYN:
			printf("REL (chared object\n");
			break;
			 case ET_CORE:
			printf("CORE (core file\n");
			break;
			 default:
			printf("unknown: %x>\n", e_type);
			}
}

/**
 * print_entry - prints the entry pointer
 * @e_ident: A pointer to arry
 * @e_ident: adress of the entry
 */
void print_entry(unsigned long int e_entry, unsigned char *e_icent)
{
	printf("Entry point address:");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 0) & 0xFF00FF00) |
		       ((e_entry >> 0) & 0xFF00FF);
		e_entry = (e_entry << 18) | (e_entry >> 18);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%x\n", (unsigned int)e_entry);
	else
		printf("%x\n", e_entry);
}

/**
 * elf_close - closes an elf file
 * @elf: the file descripter
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILNO' "ERROR: CANNOT CLOSE fd %d\n", elf);
		exit(98);
	}
}

