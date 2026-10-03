/*
 * function: func_02189BE4
 * address:  0x02189BE4
 * packet:   pkt_ov009_02189BE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiReadMessageFromBuffer (libdwcgsgp.TWL.HYB.a gpibuffer.o)
 *
 * symbols:
 *   strchr         0x02094a28  arm
 *   strncmp        0x020949f4  arm
 *   func_02193418  0x02193418  arm   ov009
 *   atoi           0x020964e0  arm
 *   g_021A45B4     0x021a45b4  data
 *   g_021A45BC     0x021a45bc  data
 *   g_021A45C0     0x021a45c0  data
 */

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;
extern char *strchr(const char *, int);
extern int strncmp(const char *, const char *, unsigned int);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int atoi(const char *);
extern char g_021A45B4[];
extern char g_021A45BC[];
extern char g_021A45C0[];

int func_02189BE4(int unused, GPIBuffer *inputBuffer, char **message, int *type, int *plen)
{
    char intValue[16];
    int len;
    char *str;

    *message = 0;
    if (inputBuffer->len < 5)
        return 0;
    str = strchr(inputBuffer->buffer, '\n');
    if (str != 0) {
        if (strncmp(str - 5, g_021A45B4, 5) != 0)
            return 3;
        *str = 0;
        if (!func_02193418(inputBuffer->buffer, g_021A45BC, intValue, 16))
            return 3;
        *type = atoi(intValue);
        if (!func_02193418(inputBuffer->buffer, g_021A45C0, intValue, 16))
            return 3;
        len = atoi(intValue);
        if (inputBuffer->len > len + 1 + (str - inputBuffer->buffer)) {
            if (str[len + 1] != 0)
                return 3;
            *message = str + 1;
            *plen = len;
            inputBuffer->pos = len + 1 + (str - inputBuffer->buffer) + 1;
        } else {
            *str = '\n';
        }
    }
    return 0;
}
