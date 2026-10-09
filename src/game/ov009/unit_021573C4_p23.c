/*
 * file:     unit_021573C4_p23.c
 * unit:     yes
 * function: func_0215AA5C, func_0215AA70, func_0215AA88, func_0215AAB0
 * address:  0x0215AA5C
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
 *   g_02150FEC  0x02150FEC  data
 *   func_0215A970  0x0215A970  arm  ov009
 *   g_021A826C  0x021A826C  data
 */
extern unsigned short func_0215A970(void);
void func_0215AA5C(int v);
void func_0215AA70(void);
void func_0215AA88(void);
void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern char g_02150FEC[];
extern char g_021A826C[];


/*
 * Stores a word at +0xa4 of the block held in the second word of the module state block.
 */
void func_0215AA5C(int v)
{
    int blk = *(int *)(g_02150FEC + 4);

    *(int *)(blk + 0xa4) = v;
}


/*
 * Clears the word at +0xa4 of the block the state object holds.
 */
void func_0215AA70(void)
{
    int *p = *(int **)(g_02150FEC + 4);

    *(int *)((char *)p + 0xa4) = 0;
}


/*
 * Puts the object at +0xa4 of the current root into mode 0xa and clears its
 * +0x50 word.
 */
void func_0215AA88(void)
{
    char *q = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (q != 0) {
        *(unsigned char *)(q + 8) = 0xa;
        *(int *)(q + 0x50) = 0;
    }
}


/*
 * sdk:      CPS_SocBind (libcps.TWL.HYB.a(network.o))
 */
void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc == 0)
        return;
    if (remote_ip == 0x7f000001)
        remote_ip = *(unsigned long *)(g_021A826C + 0x50);
    *(unsigned short *)(soc + 0x1a) = remote_port;
    *(unsigned short *)(soc + 0x18) = *(unsigned short *)(soc + 0x1a);
    *(unsigned long *)(soc + 0x20) = remote_ip;
    *(unsigned long *)(soc + 0x1c) = remote_ip;
    if (local_port != 0)
        *(unsigned short *)(soc + 0xa) = local_port;
    else
        *(unsigned short *)(soc + 0xa) = func_0215A970();
}
