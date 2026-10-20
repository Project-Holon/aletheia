"""P3VA: replace the hand-written va_* macros and va_list typedefs in src/game with sdk_stdarg.h.
Dry run by default; --apply writes. Usage: va_apply.py [--apply] file..."""
import re, sys, os
PAT = re.compile(r'^(#define (va_start|va_arg|va_end|__va_size)\b.*|typedef (unsigned )?(char|uchar) \*va_list;)\r?\n')
def rel(path):
    d = os.path.dirname(os.path.abspath(path)); up = ''
    while not os.path.exists(os.path.join(d, 'sdk_stdarg.h')):
        d = os.path.dirname(d); up += '../'
    return up + 'sdk_stdarg.h'
NL = chr(10)
EXTRA = {
    'os_printf.c': [('const char *format, void *vlist)', 'const char *format, va_list vlist)')],
    'msl_printf.c': [
        ('const u8 *format, u8 *ap)', 'const u8 *format, va_list ap)'),
        ('    u32 *p = (u32 *)((uptr)&fmt & ~3u);' + NL + NL + '    return vsnprintf((u8 *)dst, 0xFFFFFFFFu, (const u8 *)fmt, (u8 *)(p + 1));',
         '    va_list ap;' + NL + NL + '    va_start(ap, fmt);' + NL + '    return vsnprintf((u8 *)dst, 0xFFFFFFFFu, (const u8 *)fmt, ap);')],
}

def main():
    apply = '--apply' in sys.argv
    for f in [a for a in sys.argv[1:] if a != '--apply']:
        src = open(f, newline='').read().replace('\r\n', '\n')
        out, first, n = [], True, 0
        for line in src.split('\n'):
            if PAT.match(line + '\n'):
                n += 1
                if first:
                    out.append('#include "%s"' % rel(f)); first = False
                continue
            out.append(line)
        body = NL.join(out)
        for x, y in EXTRA.get(os.path.basename(f), []):
            assert x in body, (f, x)
            body = body.replace(x, y)
        out = body.split(NL)
        txt = re.sub(r'\n{3,}', '\n\n', '\n'.join(out))
        print(f, 'removed', n)
        if apply and n:
            open(f, 'w', newline='').write(txt)
main()
