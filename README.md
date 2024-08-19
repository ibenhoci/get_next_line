# get_next_line

`get_next_line` is a C function that reads a file descriptor line by line. It is designed to handle reading from both files and standard input, processing one line at a time. This implementation is optimized to work efficiently with varying buffer sizes.

## Features

- **Read One Line at a Time:** Efficiently reads a single line from a file or standard input at a time.
- **Handles Multiple Buffer Sizes:** Compiles with different buffer sizes defined via `-D BUFFER_SIZE=n`.
- **Handles End of File (EOF):** Returns `NULL` when there are no more lines to read or if an error occurs.
- **Preserves Newline Characters:** Includes the terminating `\n` character in the returned line, except when EOF is reached without a newline.

## File Structure

- `get_next_line.h`: Header file containing the prototype of the `get_next_line` function.
- `get_next_line.c`: Contains the implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Contains helper functions used by `get_next_line`.

## Compilation

To compile the `get_next_line` implementation, use the following command:

```bash
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
Replace 42 with your desired buffer size. The default buffer size can be adjusted as needed by modifying the -D BUFFER_SIZE=n flag.

## Usage
Include the header file get_next_line.h in your source code and call the get_next_line function to read lines from a file descriptor. Here is an example:
```
	#include "get_next_line.h"
	#include <fcntl.h>
	#include <stdio.h>

	int main() {
		int fd = open("example.txt", O_RDONLY);
		char *line;

		if (fd < 0) {
			perror("open");
			return 1;
		}

		while ((line = get_next_line(fd)) != NULL) {
			printf("%s", line);
			free(line);
		}

		close(fd);
		return 0;
	}
```
In this example, replace "example.txt" with the path to your file. The get_next_line function reads each line from the file and prints it until the end of the file is reached.

## Implementation Details
1. Buffer Size: The buffer size is defined at compile time using the -D BUFFER_SIZE=n flag. This allows you to test how the function behaves with different buffer sizes.
2. Reading Efficiency: The function reads data in chunks of the buffer size and processes it to extract individual lines. It avoids reading the entire file into memory, thus being efficient for large files.
3. Error Handling: Returns NULL if an error occurs or if there are no more lines to read.

## Known Issues
1. Undefined Behavior with File Changes: If the file changes between get_next_line calls, the behavior is undefined.
2. Binary Files: The function is designed for text files. Reading binary files may lead to undefined behavior.
3. Buffer Size Limits: Ensure that the buffer size is reasonable. Extremely large or small values may affect performance or functionality.

## Contributing
To contribute to this project:

1. Fork the Repository: Create a personal copy of the repository.
2. Make Changes: Implement your changes and improvements.
3. Submit a Pull Request: Share your changes with a description of what you have done.
Please ensure that your code follows the existing style and passes all tests.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments
Special thanks to contributors and educators who provided valuable insights into file handling and dynamic memory management in C.