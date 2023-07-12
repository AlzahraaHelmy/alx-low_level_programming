#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *fname, size_t letters);
int create_file(const char *fname, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
