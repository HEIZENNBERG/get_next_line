// void gg()
// {
//     system("leaks a.out");
// }
// int main()
// {
//     atexit(gg);
//     int fd = open("test.txt", O_RDONLY | O_RDWR, 0777);
	
//     char *dd = get_next_line(fd);
//     printf("main   :   %s\n", dd);

//     dd = get_next_line(fd);
//     printf("main   :   %s\n", dd);

//     dd = get_next_line(fd);
//     printf("main   :   %s\n", dd);

	
//     dd = get_next_line(fd);
//     printf("main   :   %s\n", dd);
	
//     dd = get_next_line(fd);
//     printf("main   :   %s\n", dd);

//     free(dd);
// }