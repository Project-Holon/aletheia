/*
 * file:     unit_0215F2DC_p01.c
 * unit:     yes
 * function: func_0215F2DC, func_0215F2F4, func_0215F304, func_0215F31C
 * address:  0x0215F2DC
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
 *   g_021AA4B4  0x021AA4B4  data
 *   func_0215F2F4  0x0215F2F4  arm  ov009
 *   g_021AA4B8  0x021AA4B8  data
 *   func_0215F334  0x0215F334  arm  ov009
 */
struct Sock;
extern void func_0215F2F4(char *p, int a);
extern void func_0215F334(struct Sock **next, struct Sock *socket);
void func_0215F2DC(int a);
void SOCLi_SocketRegisterList(void **next, char *socket);
void func_0215F304(int a);
void func_0215F31C(int a);
extern char g_021AA4B4[];
extern char g_021AA4B8[];


void func_0215F2DC(int a)
{
    func_0215F2F4(g_021AA4B4, a);
}

void SOCLi_SocketRegisterList(void **next, char *socket)
{
	*(void **)(socket + 0xb8) = *next;
	*next = socket;
}


/*
 * Tail call on the object at 0x021AA4B8 with the incoming argument.
 */
void func_0215F304(int a)
{
    func_0215F2F4(g_021AA4B8, a);
}


/*
 * Tail call on the object at 0x021AA4B4 with the incoming argument.
 */
void func_0215F31C(int a)
{
    func_0215F334((struct Sock **)g_021AA4B4, (struct Sock *)a);
}
