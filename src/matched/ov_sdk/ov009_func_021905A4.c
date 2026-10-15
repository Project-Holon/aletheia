/*
 * function: func_021905A4
 * address:  0x021905A4
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiCreateSearchData-alike: allocate a 0x1a0-byte GPISearchData, clear it,
 * default the socket to -1 and the type to the caller's, hand the caller a
 * 0x1001-byte output buffer (size field 0x1000), and publish the object
 * through *out.  Returns 1 (and sets the "Out of memory" error string) when
 * either allocation fails, else 0.
 *
 * symbols:
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A5280     0x021A5280  data ov009
 */

typedef struct {
    char *data;
    int size;
    int len;
} GPIBuffer;

typedef struct {
    int type;
    int sock;
    GPIBuffer inputBuffer;
    int unk14;
    GPIBuffer outputBuffer;
    int unk24;
    char pad[0x15c];
    int processing;
    int remove;
    int searchStartTime;
    int revBuddyProfileIds;
    int numOfRevBuddyProfiles;
    int unk198;
    int unk19c;
} GPISearchData;

extern void *func_0217EAB0(int size);
typedef unsigned int   u32;
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern void func_02193734(int *p, int b);
extern char g_021A5280[];

int func_021905A4(int connection, GPISearchData **out, int type)
{
    GPISearchData *data = func_0217EAB0(0x1a0);

    if (data == 0) {
        func_02193734((int *)connection, (int)g_021A5280);
        return 1;
    }
    MSL_C_LIB_MemsetPtr(data, 0, 0x1a0);
    data->type = type;
    data->sock = -1;
    data->inputBuffer.data = 0;
    data->inputBuffer.len = 0;
    data->unk14 = 0;
    data->inputBuffer.size = 0;
    data->outputBuffer.len = 0;
    data->unk24 = 0;
    data->outputBuffer.size = 0x1000;
    data->outputBuffer.data = func_0217EAB0(0x1001);
    if (data->outputBuffer.data == 0) {
        func_02193734((int *)connection, (int)g_021A5280);
        return 1;
    }
    data->processing = 0;
    data->remove = 0;
    *out = data;
    return 0;
}
