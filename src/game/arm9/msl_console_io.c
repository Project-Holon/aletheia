/*
 * file:     msl_console_io.c
 * unit:     yes
 * function: func_0209D724, func_0209D728, func_0209D774, func_0209D778, func_0209D77C, func_0209D784, func_0209D7D4, func_0209D818, func_0209D820, __register_global_object
 * address:  0x0209D724
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * MSL C console I/O tail after the runtime.a routines: the empty finaliser
 * at 0x0209D724, a 64-entry table writer, the console read/write/close
 * hooks and the callback-table walker at 0x0209D820.
 * func_0209D818 is the close hook: the FILE tables at 0x020A876C and
 * 0x020A87B8 hold func_0209D784, func_0209D7D4, func_0209D818 in a row.
 * note:     EXACT* not EXACT: scan_listing finds no func_ label between
 *           0x0209D850 and 0x020A8FE6, so target_extent reports 46998 bytes
 *           while the compiled function is 32.  The next real label after
 *           this run of list nodes and descriptor data is far below.
 *
 * symbols:
 *   g_02153FB4  0x02153FB4  data
 *   g_02153FB8  0x02153FB8  data
 *   __global_destructor_chain  0x021542B8  data
 */
typedef unsigned char u8;

typedef unsigned int   u32;

typedef void (*Handler)(void);

struct DestructorChain
{
    struct DestructorChain *next;
    u32 destructor;
    u32 object;
};

void func_0209D724(void);
int func_0209D728(int a);
void func_0209D774(void *p);
void func_0209D778(void *str);
int func_0209D77C(void);
u32 func_0209D784(u32 a, char *dest, u32 *count);
int func_0209D7D4(int handle, u8 *buffer, u32 *count);
int func_0209D818(int handle);
void func_0209D820(void);
void __register_global_object(u32 object, u32 destructor, struct DestructorChain *chain);
extern int   g_02153FB4;
extern struct DestructorChain g_02153FB8[];
extern struct DestructorChain *__global_destructor_chain;


/*
 * layout/runtime_arm9.txt lists 0x0209D724 as _runtime_null_stub and claims
 * it is hand-written assembly. It is a bare 4-byte `bx lr`, which an empty
 * compiled C function reproduces byte for byte, so the row is over-broad and
 * the integrator may drop it. Reported from the runtime-library audit lane
 * (0x0209C2B0..0x0209D724).
 */
void func_0209D724(void)
{
}


/*
 * blocked:  the only occurrences of 0x02153FB4 and 0x02153FB8 in the image are the two
 *           pool words at 0x0209D76C and 0x0209D770, inside this function's own compared
 *           range, so the data class has no outside witness. MATCH, byte-exact.
 */
int func_0209D728(int a)
{
    int r = 0;

    if (g_02153FB4 == 0x40)
        return -1;

    __register_global_object(r, a, &g_02153FB8[g_02153FB4++]);
    return r;
}

void func_0209D774(void *p){ }


void func_0209D778(void *str){ }

int func_0209D77C(void){ return 0; }


u32 func_0209D784(u32 a, char *dest, u32 *count)
{
    u32 i;
    u32 n = *count;
    for (i = 0; i < n; i++)
    {
        int c = func_0209D77C();
        dest[i] = (char)c;
        if ((u8)c == '\r' || (u8)c == '\n')
        {
            *count = i + 1;
            break;
        }
    }
    return 0;
}


/*
 * MSL console write hook (the __write_console shape: handle, buffer,
 * size_t *count, returns 0): terminate the buffer's last byte, emit the
 * buffer, then emit the saved byte.  Both callees are bare `bx lr` stubs
 * in this release build.
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 43
 * (docs/notes/func_0209D7D4.c.txt).  The lever is the ARITY of
 * func_0209D778: it takes ONE argument.  The image's `mov r1, #0` is not a
 * second argument but the register the compiler picked for the terminator
 * store, free once `mov r0, r1` has consumed buffer; every earlier spelling
 * passed `(buffer, 0)`, which made the zero an argument CSE'd with the
 * store and forced it into r2 with a `mov r1, r2` copy (72 bytes).  With
 * the one-argument prototype the body is 68 bytes, 0 out.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0209D7D4.c \
 *       --func func_0209D7D4 --addr 0x0209D7D4 --arm --cc 1.1p1
 */
int func_0209D7D4(int handle, u8 *buffer, u32 *count)
{
    if (*count > 1) {
        u8 *end = buffer + *count;
        u8 c = end[-1];
        end[-1] = 0;
        func_0209D778(buffer);
        func_0209D774(&c);
    } else {
        func_0209D774(buffer);
    }
    return 0;
}


int func_0209D818(int handle)
{
    return 0;
}


void func_0209D820(void)
{
    Handler *p = (Handler *)0x020A64F8;
    while (p != 0 && *p != 0)
    {
        (*p)();
        p++;
    }
}


void __register_global_object(u32 object, u32 destructor, struct DestructorChain *chain)
{
    chain->next = __global_destructor_chain;
    chain->destructor = destructor;
    chain->object = object;
    __global_destructor_chain = chain;
}
