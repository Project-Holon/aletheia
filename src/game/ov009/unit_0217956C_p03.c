/*
 * file:     unit_0217956C_p03.c
 * unit:     yes
 * function: func_02179CF4, func_02179DA0, func_02179E60
 * address:  0x02179CF4
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
 *   func_0217A808  0x0217A808  arm  ov009
 *   func_0217A120  0x0217A120  arm  ov009
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217A0D4  0x0217A0D4  arm  ov009
 *   func_02084F80  0x02084F80  arm
 *   g_021A2608     0x021A2608  data
 *   g_021A265C     0x021A265C  data
 *   func_0217A15C  0x0217A15C  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_02092364  0x02092364  arm
 *   g_021A267C     0x021A267C  data
 *   g_021A25D4     0x021A25D4  data
 */
typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;

typedef unsigned char  u8;

extern void func_0217A808(char *http, void *array_entry, int array_len);
extern void func_0217A120(char *http, void *buf);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_0209477C(const u8 *s);
extern int func_0217A0D4(char *http, Buf *buf, unsigned long size);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern int func_0217A15C(char *http, Buf *buf, int size);
extern char *func_02094B20(const char *s, const char *sub);
extern void *func_02092364(void *dst, const void *src, unsigned long n);
void func_02179CF4(char *http);
int func_02179DA0(char *http);
int func_02179E60(char *http, char *label, char *data);
extern char g_021A2608[];
extern char g_021A265C[];
extern char g_021A267C[];
extern char g_021A25D4[];


/*
 * sdk:      DWC_Http_Destroy (dwc_http.o)
 */
void func_02179CF4(char *http)
{
    void (*free)(unsigned long, void *, long) =
        *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (http == 0) {
        return;
    }
    func_0217A808(http, http + 0x1a74, 0x20);
    func_0217A120(http, http + 0x1a44);
    func_0217A120(http, http + 0x1a34);
    if (*(void **)(http + 0x1a08) != 0) {
        free(0, *(void **)(http + 0x1a08), 0);
        *(void **)(http + 0x1a08) = 0;
    }
    if (*(void **)(http + 0x1a0c) != 0) {
        free(0, *(void **)(http + 0x1a0c), 0);
        *(void **)(http + 0x1a0c) = 0;
    }
    MI_CpuFill8(http, 0, 0x1c50);
}


/*
 * sdk:      DWCi_Http_WriteBasicHeader (dwc_http.o)
 */
int func_02179DA0(char *http)
{
    char *format;
    Buf *req;
    int result_len;

    req = (Buf *)(http + 0x1a34);
    if (*(int *)(http + 0x1008) == 0) {
        format = g_021A2608;
    } else {
        format = g_021A265C;
    }
    result_len = func_0209477C((const u8 *)(*(char **)(http + 0x1124))) +
                 (func_0209477C((const u8 *)format) - 4 + func_0209477C((const u8 *)(*(char **)(http + 0x1128))));
    if (func_0217A0D4(http, (Buf *)(http + 0x1a34), result_len + 0x400) != 1) {
        return 1;
    }
    result_len = func_02084F80(req->cur, req->cap, format, *(char **)(http + 0x1128), *(char **)(http + 0x1124));
    req->cur += result_len;
    return 0;
}


/*
 * sdk:      DWC_Http_Add_HeaderItem (dwc_http.o)
 */
int func_02179E60(char *http, char *label, char *data)
{
    Buf *temp_buffer;
    int buf_remain;
    int result_len;
    char temp;
    char *temp_index;

    temp_buffer = (Buf *)(http + 0x1a34);
    result_len = func_0209477C((const u8 *)data) +
                 (func_0209477C((const u8 *)g_021A267C) - 4 + func_0209477C((const u8 *)label));
    buf_remain = temp_buffer->end - temp_buffer->cur;
    if (result_len + 1 > buf_remain) {
        if (func_0217A15C(http, temp_buffer, result_len - buf_remain + 1) == 0) {
            return 1;
        }
    }
    temp_index = func_02094B20(temp_buffer->base, g_021A25D4) + 2;
    temp = *temp_index;
    func_02092364(temp_index + result_len, temp_index, func_0209477C((const u8 *)temp_index) + 1);
    temp_index[func_02084F80(temp_index, result_len + 1, g_021A267C, label, data)] = temp;
    temp_buffer->cur += result_len;
    return 0;
}
