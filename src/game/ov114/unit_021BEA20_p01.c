/*
 * file:     unit_021BEA20_p01.c
 * unit:     yes
 * function: func_021BEA98, func_021BEAB8, func_021BEB88
 * address:  0x021BEA98
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEA20  0x021BEA20  arm  ov114
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 *   g_021CF984 0x021CF984 data
 *   g_021CF984_hdr 0x021CF984 data
 */
#include "../../matched/include/G_Conn.h"

struct Conn;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Conn Conn;

extern u8 *func_021BEA20(void);
extern void func_02085800(void *, int);
extern void func_021BEFCC(void);
extern void func_021BEFD8(void *mutexInfo_p);
void func_021BEA98(u8 *p);
Conn *func_021BEAB8(void *mutexInfo_p, Conn *handle_p, unsigned long order);
int func_021BEB88(int a, int b);
extern struct Conn *g_021CF984;
extern struct Conn *g_021CF984_hdr;


/*
 * Clears the +0x0c queue of `p` and re-arms the +0x1c resource.
 */
void func_021BEA98(u8 *p)
{
    u8 *q = func_021BEA20();
    *(u32 *)(p + 0xc) = 0;
    func_02085800(q + 0x1c, 0);
}


Conn *func_021BEAB8(void *mutexInfo_p, Conn *handle_p, unsigned long order)
{
    Conn *ret_p = 0;
    Conn **connection_pp;
    Conn *connection_p;

    func_021BEFCC();
    if (order == 3) {
        ret_p = handle_p;
        handle_p->next = g_021CF984;
        g_021CF984 = handle_p;
    } else {
        connection_pp = &g_021CF984_hdr;
        connection_p = g_021CF984;
        while (connection_p != 0) {
            switch (order) {
            case 0:
                if (connection_p == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 1:
                if (connection_p->f10 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 2:
                if (connection_p->f14 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 4:
                if (connection_p == handle_p) {
                    ret_p = *connection_pp;
                    *connection_pp = ret_p->next;
                }
                break;
            }
            if (ret_p != 0) {
                break;
            }
            connection_pp = &(*connection_pp)->next;
            connection_p = *connection_pp;
        }
    }
    func_021BEFD8(mutexInfo_p);
    return ret_p;
}


int func_021BEB88(int a, int b)
{
    return -(func_021BEAB8((void *)a, (struct Conn *)b, 3) == 0);
}
