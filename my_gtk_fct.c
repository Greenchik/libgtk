void*	gtk_memset(void* s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char*)(s + i)) = (char)c;
		i = i + 1;
	}
	return (s);
}
