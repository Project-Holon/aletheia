/*
 * function: func_0219091C
 * address:  0x0219091C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef enum {
    GP_NO_ERROR = 0,
    GP_MEMORY_ERROR = 1,
    GP_PARAMETER_ERROR = 2,
    GP_NETWORK_ERROR = 3,
    GP_SERVER_ERROR = 4
} GPResult;

struct GPConnection {
    void *p3d;
};

struct GPISearchData {
    u32 type;
    void *sock;
    u32 state;
};

struct GPIOperation {
    u32 pad0;
    struct GPISearchData *searchData;
    u32 type;
    u32 padC[2];
    u32 state;
};

extern u32 current_time(void);
extern void gpiSetError(void *connection, void *error, void *string);
extern void gpiSetErrorString(void *connection, u32 result, u32 error);
extern u32 gpiCheckSocketConnect(void *connection, void *sock, void *state, void *buf);
extern u32 gpiValueForKey(void *connection, void *sock, void *buf);
extern void gpiAppendStringToBuffer(void *connection, void *buf, const char *str);
extern void gpiAppendIntToBuffer(void *connection, void *buf, int val);

GPResult func_0219091C(struct GPConnection *connection, struct GPIOperation *operation)
{
    u8 buffer[0x4d4];
    void *p3d;
    struct GPISearchData *searchData;
    void *op;
    u32 is_type_set;
    GPResult error;
    u32 now;
    u32 *p18c;
    int r8;
    int sb;
    int sl;
    int fp;

    p3d = connection->p3d;
    op = operation->searchData;
    searchData = (struct GPISearchData *)op;
    is_type_set = (operation->type != 0) ? 1 : 0;
    r8 = is_type_set;
    error = GP_NETWORK_ERROR;

    if (operation->type == 0) {
        now = current_time();
        p18c = (u32 *)((char *)searchData + 0x18c);
        if (now - *p18c > 0xed0) {
            *(u32 *)((char *)searchData + 0x188) = 1;
            gpiSetError(connection, (void *)0xec4, (void *)0xec4);
            gpiSetErrorString(connection, error, 0);
            return error;
        }
    }

    sb = 1;
    *(u32 *)buffer = sb;
    *(u32 **)(buffer + 4) = (u32 *)0xed0; // placeholder to pin scratch registers

    if (gpiCheckSocketConnect(connection, *(void **)((char *)searchData + 4), (char *)searchData + 0x18, buffer + 0x7c) != 0) {
        return GP_NO_ERROR;
    }

    if (operation->state == 1) {
        if (gpiValueForKey(connection, *(void **)((char *)searchData + 4), buffer + 0x90) != 0) {
            return GP_NO_ERROR;
        }
    }

    return GP_NO_ERROR;
}
