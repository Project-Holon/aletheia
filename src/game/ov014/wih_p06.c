/*
 * file:     wih_p06.c
 * unit:     yes
 * function: func_02178304, func_021783FC, func_021784AC
 * address:  0x02178304
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A8                  0x021797A8  data   ov014  a4
 *   d_02179794                  0x02179794  data   ov014  a1
 *   func_0217814C               0x0217814C  thumb  ov014
 *   func_02178138               0x02178138  thumb  ov014
 *   WM_GetMPSendBufferSize      0x0208EC34  arm
 *   WM_GetMPReceiveBufferSize   0x0208ECA4  arm
 *   WM_StartMP                  0x0208FC4C  arm
 *   func_0203D7FC               0x0203D7FC  arm
 *   func_0203D7C8               0x0203D7C8  arm
 *   func_0203D5D4               0x0203D5D4  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0209004C  0x0209004C  arm
 *   func_021784D0 0x021784D0 thumb ov014
 *   func_0208FDEC 0x0208FDEC arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int BOOL;

extern void func_0217814C(int err);
extern void func_02178138(int state);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void func_0203D7FC(void *p);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern u32 func_0203D5D4(void);
u32 func_0203D6BC(void);
u32 func_0203D680(void);
int func_0209004C(void *p, u32 a, u32 b, u16 c, u32 d);
extern void func_021784D0(void *);
extern int func_0208FDEC(void (*)(void *));
BOOL func_02178304(void);
void func_021783FC(u16 *a);
int func_021784AC(void);
extern u8 *g_021797A8;
extern char d_02179794[];


/*
 * Twin of func_02178AB8 (the DWC copy of the NitroSDK wh.c MP start), with a
 * state guard in front: states 4 and 5 (+0x1E70) already run MP, else the
 * state setter func_02178138(4) runs first, and the callback is
 * func_021783FC.
 */
BOOL func_02178304(void)
{
    int result;
    u16 freq;

    if (*(int *)(g_021797A8 + 0x1E70) == 4 || *(int *)(g_021797A8 + 0x1E70) == 5)
        return 1;

    func_02178138(4);

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (*(void **)(g_021797A8 + 0x1E6C) != 0) {
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E6C));
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E68));
    }

    *(int *)(g_021797A8 + 0x1E90) = WM_GetMPReceiveBufferSize();
    *(int *)(g_021797A8 + 0x1E8C) = WM_GetMPSendBufferSize();

    *(void **)(g_021797A8 + 0x1E6C) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E90) + 0x20, d_02179794, 0x4A7);
    *(void **)(g_021797A8 + 0x1E68) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E8C) + 0x20, d_02179794, 0x4A8);

    freq = (func_0203D5D4() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))func_021783FC,
                        *(void **)(g_021797A8 + 0x1E6C),
                        (u16)*(int *)(g_021797A8 + 0x1E90),
                        *(void **)(g_021797A8 + 0x1E68),
                        (u16)*(int *)(g_021797A8 + 0x1E8C),
                        freq);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}


void func_021783FC(u16 *a)
{
    u16 v1 = a[1];
    u16 mask;
    u32 id;
    u32 flag;
    u32 n;
    int r;
    if (v1 != 0) {
        func_0217814C(v1);
        func_02178138(9);
        return;
    }
    switch (a[2]) {
    case 10:
        if (*(int *)(g_021797A8 + 0x1E74) == 4) {
            id = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (1 << (n + 1)) - 1;
            flag = 1;
            if (func_0203D5D4() == 2)
                flag = 0;
            r = func_0209004C(g_021797A8 + 0x1444, 13, mask, id, flag);
            if (r != 0) {
                func_0217814C(r);
                func_02178138(9);
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}

int func_021784AC(void)
{
    int result;
    func_02178138(3);
    result = func_0208FDEC(func_021784D0);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}
