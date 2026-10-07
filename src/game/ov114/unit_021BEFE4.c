/*
 * file:     unit_021BEFE4.c
 * unit:     yes
 * function: func_021BEFE4, func_021BF018
 * address:  0x021BEFE4
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
 *   func_021BEFCC   0x021BEFCC  arm
 *   func_021BEFD8   0x021BEFD8  arm
 */
typedef unsigned long u32;

extern void func_021BEFCC(void);
extern void func_021BEFD8(void *mutexInfo_p);
int NHTTPi_addRef(void *mutexInfo_p, char *connection_p);
int NHTTPi_decRef(void *mutexInfo_p, char *connection_p);


int NHTTPi_addRef(void *mutexInfo_p, char *connection_p)
{
    func_021BEFCC();
    ++*(u32 *)(connection_p + 0x8048);
    func_021BEFD8(mutexInfo_p);
    return *(u32 *)(connection_p + 0x8048);
}


int NHTTPi_decRef(void *mutexInfo_p, char *connection_p)
{
    func_021BEFCC();
    --*(u32 *)(connection_p + 0x8048);
    func_021BEFD8(mutexInfo_p);
    return *(u32 *)(connection_p + 0x8048);
}
