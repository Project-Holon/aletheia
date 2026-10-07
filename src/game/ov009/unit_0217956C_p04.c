/*
 * file:     unit_0217956C_p04.c
 * unit:     yes
 * function: func_0217A044, func_0217A0C8
 * address:  0x0217A044
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_0217A15C  0x0217A15C  arm  ov009
 *   func_02084F80  0x02084F80  arm
 *   g_021A2694     0x021A2694  data
 */
typedef struct {
    int unk0;
    char *cur;
    char *end;
} Buf;

typedef unsigned char  u8;

extern int func_0209477C(const u8 *s);
extern int func_0217A15C(char *http, Buf *buf, int size);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
int func_0217A044(char *http, char *data);
int DWCi_Http_CPSCallback(int result);
extern char g_021A2694[];


/*
 * sdk:      DWC_Http_Add_Body (dwc_http.o)
 */
int func_0217A044(char *http, char *data)
{
    int result_len;
    int buf_remain;
    int temp;
    Buf *temp_buffer;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = func_0209477C((const u8 *)data);
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len > buf_remain) {
        if (func_0217A15C(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
        buf_remain = temp_buffer->end - temp_buffer->cur;
    }
    temp = func_02084F80(temp_buffer->cur, buf_remain, g_021A2694, data);
    if (temp != result_len) {
        return 1;
    }
    temp_buffer->cur += temp;
    return 0;
}

int DWCi_Http_CPSCallback(int result)
{
	if (result & 0x8000)
		result &= ~0x8000;
	return result;
}
