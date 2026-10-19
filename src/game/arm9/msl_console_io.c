/*
 * file:     msl_console_io.c
 * unit:     yes
 * function: MSL_CONSOLE_IO_NoopFinalizer, MSL_CONSOLE_IO_RegisterDestructor, MSL_CONSOLE_IO_WriteChar, MSL_CONSOLE_IO_WriteString, MSL_CONSOLE_IO_ReadChar, MSL_CONSOLE_IO_ReadConsole, MSL_CONSOLE_IO_WriteConsole, MSL_CONSOLE_IO_CloseConsole, MSL_CONSOLE_IO_RunInitHandlers, __register_global_object
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
 * MSL_CONSOLE_IO_CloseConsole is the close hook: the FILE tables at 0x020A876C and
 * 0x020A87B8 hold MSL_CONSOLE_IO_ReadConsole, MSL_CONSOLE_IO_WriteConsole, MSL_CONSOLE_IO_CloseConsole in a row.
 * note:     EXACT* not EXACT: scan_listing finds no func_ label between
 *           0x0209D850 and 0x020A8FE6, so target_extent reports 46998 bytes
 *           while the compiled function is 32.  The next real label after
 *           this run of list nodes and descriptor data is far below.
 *
 * symbols:
 *   gDestructorCount  0x02153FB4  data
 *   gDestructorChains  0x02153FB8  data
 *   __global_destructor_chain  0x021542B8  data
 */
#include "../types.h"

typedef void (*Handler)(void);

struct DestructorChain
{
    struct DestructorChain *next;
    u32 destructor;
    u32 object;
};

void MSL_CONSOLE_IO_NoopFinalizer(void);
int MSL_CONSOLE_IO_RegisterDestructor(int a);
void MSL_CONSOLE_IO_WriteChar(void *p);
void MSL_CONSOLE_IO_WriteString(void *str);
int MSL_CONSOLE_IO_ReadChar(void);
u32 MSL_CONSOLE_IO_ReadConsole(u32 a, char *dest, u32 *count);
int MSL_CONSOLE_IO_WriteConsole(int handle, u8 *buffer, u32 *count);
int MSL_CONSOLE_IO_CloseConsole(int handle);
void MSL_CONSOLE_IO_RunInitHandlers(void);
void __register_global_object(u32 object, u32 destructor, struct DestructorChain *chain);
extern int   gDestructorCount;
extern struct DestructorChain gDestructorChains[];
extern struct DestructorChain *__global_destructor_chain;

/*
 * layout/runtime_arm9.txt lists 0x0209D724 as _runtime_null_stub and claims
 * it is hand-written assembly. It is a bare 4-byte `bx lr`, which an empty
 * compiled C function reproduces byte for byte, so the row is over-broad and
 * the integrator may drop it. Reported from the runtime-library audit lane
 * (0x0209C2B0..0x0209D724).
 */
void MSL_CONSOLE_IO_NoopFinalizer(void)
{
}

/*
 * blocked:  the only occurrences of 0x02153FB4 and 0x02153FB8 in the image are the two
 *           pool words at 0x0209D76C and 0x0209D770, inside this function's own compared
 *           range, so the data class has no outside witness. MATCH, byte-exact.
 */
int MSL_CONSOLE_IO_RegisterDestructor(int destructor)
{
    int result = 0;

    if (gDestructorCount == 0x40)
        return -1;

    __register_global_object(result, destructor, &gDestructorChains[gDestructorCount++]);
    return result;
}

void MSL_CONSOLE_IO_WriteChar(void *string){ }

void MSL_CONSOLE_IO_WriteString(void *string){ }

int MSL_CONSOLE_IO_ReadChar(void){ return 0; }

u32 MSL_CONSOLE_IO_ReadConsole(u32 handle, char *dest, u32 *count)
{
    u32 index;
    u32 n = *count;
    for (index = 0; index < n; index++)
    {
        int ch = MSL_CONSOLE_IO_ReadChar();
        dest[index] = (char)ch;
        if ((u8)ch == '\r' || (u8)ch == '\n')
        {
            *count = index + 1;
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
 * (docs/notes/MSL_CONSOLE_IO_WriteConsole.c.txt).  The lever is the ARITY of
 * MSL_CONSOLE_IO_WriteString: it takes ONE argument.  The image's `mov r1, #0` is not a
 * second argument but the register the compiler picked for the terminator
 * store, free once `mov r0, r1` has consumed buffer; every earlier spelling
 * passed `(buffer, 0)`, which made the zero an argument CSE'd with the
 * store and forced it into r2 with a `mov r1, r2` copy (72 bytes).  With
 * the one-argument prototype the body is 68 bytes, 0 out.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MSL_CONSOLE_IO_WriteConsole.c \
 *       --func MSL_CONSOLE_IO_WriteConsole --addr 0x0209D7D4 --arm --cc 1.1p1
 */
int MSL_CONSOLE_IO_WriteConsole(int handle, u8 *buffer, u32 *count)
{
    if (*count > 1) {
        u8 *end = buffer + *count;
        u8 savedByte = end[-1];
        end[-1] = 0;
        MSL_CONSOLE_IO_WriteString(buffer);
        MSL_CONSOLE_IO_WriteChar(&savedByte);
    } else {
        MSL_CONSOLE_IO_WriteChar(buffer);
    }
    return 0;
}

int MSL_CONSOLE_IO_CloseConsole(int handle)
{
    return 0;
}

void MSL_CONSOLE_IO_RunInitHandlers(void)
{
    Handler *handler = (Handler *)0x020A64F8;
    while (handler != 0 && *handler != 0)
    {
        (*handler)();
        handler++;
    }
}

void __register_global_object(u32 object, u32 destructor, struct DestructorChain *chain)
{
    chain->next = __global_destructor_chain;
    chain->destructor = destructor;
    chain->object = object;
    __global_destructor_chain = chain;
}
