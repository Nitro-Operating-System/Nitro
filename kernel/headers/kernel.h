void kprint(const char* data);
void initalize_kernel(void);
void cls(void);
void term_init(int fg, int bg);
int text_color;
void terminal_putchar(char c);
void timeout(int delay);
void refresh_color(int fg, int bg);
