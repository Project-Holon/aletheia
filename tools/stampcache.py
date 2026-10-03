#!/usr/bin/env python3
"""Stamp-validated pickle caches for the tools that read thousands of files.

Every tool used to re-open the 30k sources, the shard json files and the
listings on each call.  A scandir walk gives (name, mtime_ns, size) for each
file almost for free.  A cache keeps one parsed value per file next to the
stamp it was parsed at.  A run parses only the files whose stamp changed.

    cache = stampcache.Cache("shards", owners=[__file__])
    values = cache.sync(stampcache.scan_files(dirpath, (".json",)), parse)

`parse(path)` returns a picklable value.  An exception from parse is not
cached: it propagates and the next run parses the file again.

The cache key holds the stamp of each owner file (the reading tool's own
source), so editing the tool drops its cache.  A cache file is written to a
temporary name and moved into place with os.replace, so a reader never sees a
half-written file.  Any read or write failure means "no cache".

The folder is build/cache (git-ignored).  Set ALETHEIA_CACHE_DIR to use
another folder.  Set ALETHEIA_NO_CACHE=1 to bypass the cache.
"""

import hashlib
import os
import pickle
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCHEMA = 1


def cache_dir():
    return os.environ.get("ALETHEIA_CACHE_DIR") or os.path.join(ROOT, "build", "cache")


def disabled():
    return bool(os.environ.get("ALETHEIA_NO_CACHE"))


def stamp_of(path):
    """(name, mtime_ns, size) of one file, or None when it is missing."""
    try:
        st = os.stat(path)
    except OSError:
        return None
    return (os.path.basename(path), st.st_mtime_ns, st.st_size)


def owner_key(paths):
    """A hashable key from the stamps of the files that define a cache's shape."""
    out = [sys.version_info[:3], SCHEMA]
    for p in paths:
        out.append(stamp_of(p))
    return tuple(out)


def scan_files(dirpath, suffixes=None):
    """[(name, path, mtime_ns, size)] for the files in one directory, by name.

    One scandir pass.  On Windows the stat comes with the directory entry, so
    this does not open or stat each file again."""
    out = []
    try:
        it = os.scandir(dirpath)
    except OSError:
        return out
    with it:
        for e in it:
            n = e.name
            if suffixes is not None and not n.endswith(suffixes):
                continue
            try:
                if not e.is_file():
                    continue
                st = e.stat()
            except OSError:
                continue
            out.append((n, e.path, st.st_mtime_ns, st.st_size))
    out.sort(key=lambda t: t[0])
    return out


def scan_subdirs(dirpath):
    """[(name, path)] for the sub-directories of one directory, by name."""
    out = []
    try:
        it = os.scandir(dirpath)
    except OSError:
        return out
    with it:
        for e in it:
            try:
                if e.is_dir():
                    out.append((e.name, e.path))
            except OSError:
                continue
    out.sort(key=lambda t: t[0])
    return out


def walk_files(top, suffixes=None):
    """[(relpath, path, mtime_ns, size)] for every file under `top`, by relpath.

    relpath uses "/" and is relative to `top`.  One scandir call per folder."""
    out = []
    stack = [("", top)]
    while stack:
        rel, d = stack.pop()
        try:
            it = os.scandir(d)
        except OSError:
            continue
        with it:
            for e in it:
                try:
                    if e.is_dir():
                        stack.append((rel + e.name + "/", e.path))
                        continue
                    if suffixes is not None and not e.name.endswith(suffixes):
                        continue
                    st = e.stat()
                except OSError:
                    continue
                out.append((rel + e.name, e.path, st.st_mtime_ns, st.st_size))
    out.sort(key=lambda t: t[0])
    return out


class Cache:
    """One pickle file holding {key: value} for a set of files."""

    def __init__(self, name, owners=(), extra=None):
        self.name = name
        self.path = os.path.join(cache_dir(), name + ".pkl")
        self.version = (owner_key(owners), extra)

    def _load(self):
        if disabled():
            return {}, {}
        try:
            with open(self.path, "rb") as fh:
                blob = pickle.load(fh)
            if blob.get("version") == self.version:
                return blob["stamps"], blob["vals"]
        except Exception:
            pass
        return {}, {}

    def save(self, stamps, vals):
        """Write the cache atomically.  Failure is silent."""
        if disabled():
            return
        tmp = "%s.%d.tmp" % (self.path, os.getpid())
        try:
            os.makedirs(os.path.dirname(self.path), exist_ok=True)
            with open(tmp, "wb") as fh:
                pickle.dump({"version": self.version, "stamps": stamps,
                             "vals": vals}, fh, pickle.HIGHEST_PROTOCOL)
            for attempt in range(6):
                try:
                    os.replace(tmp, self.path)
                    return
                except PermissionError:
                    time.sleep(0.05 * (attempt + 1))
        except Exception:
            pass
        try:
            os.remove(tmp)
        except OSError:
            pass

    def sync(self, files, parse, key=None, on_error=None):
        """{key: value} for `files`, parsing only files whose stamp changed.

        `files` is [(name, path, mtime_ns, size)] as scan_files() returns it,
        or any list of such tuples.  `key` maps a tuple to the dict key
        (default: the path).  The result keeps the order of `files`.

        With `on_error`, a parse that raises Exception is reported as
        on_error(tuple, exception), left out of the result and never cached."""
        old_st, old_v = self._load()
        stamps = {}
        vals = {}
        changed = False
        for t in files:
            k = key(t) if key else t[1]
            s = (t[2], t[3])
            if old_st.get(k) == s and k in old_v:
                stamps[k] = s
                vals[k] = old_v[k]
                continue
            try:
                v = parse(t[1])
            except Exception as exc:
                if on_error is None:
                    raise
                on_error(t, exc)
                continue
            vals[k] = v
            stamps[k] = s
            changed = True
        if changed or len(vals) != len(old_v):
            self.save(stamps, vals)
        return vals


class FileCache:
    """One small pickle per key, for values that are large or used one at a time.

    Cache.sync() keeps a whole file set in one pickle, which suits a scan that
    needs every file.  A lookup that wants one listing out of 237 would load
    them all, and a cold run would rewrite the one pickle after every listing.
    FileCache keeps each value in its own file under build/cache/<kind>/.

        fc = stampcache.FileCache("ovdata", owners=[__file__])
        value = fc.get(key, stamp, build)

    `stamp` is any picklable value that changes when the inputs change (the
    file stamps, plus anything else the value depends on).  `build()` makes
    the value on a miss.  A key that is a path outside the repository (a
    temporary file of a self-test) is built and not stored."""

    def __init__(self, kind, owners=(), extra=None):
        self.dir = os.path.join(cache_dir(), kind)
        self.version = (owner_key(owners), extra)

    def _file(self, key):
        return os.path.join(self.dir, hashlib.sha1(key.encode("utf-8", "replace")).hexdigest()[:24] + ".pkl")

    def _cacheable(self, key):
        if disabled():
            return False
        if os.path.isabs(key):
            try:
                rel = os.path.relpath(key, ROOT)
            except ValueError:
                return False
            return not rel.startswith("..")
        return True

    def get(self, key, stamp, build):
        if not self._cacheable(key):
            return build()
        path = self._file(key)
        try:
            with open(path, "rb") as fh:
                blob = pickle.load(fh)
            if (blob["version"] == self.version and blob["key"] == key
                    and blob["stamp"] == stamp):
                return blob["val"]
        except Exception:
            pass
        val = build()
        tmp = "%s.%d.tmp" % (path, os.getpid())
        try:
            os.makedirs(self.dir, exist_ok=True)
            with open(tmp, "wb") as fh:
                pickle.dump({"version": self.version, "key": key, "stamp": stamp,
                             "val": val}, fh, pickle.HIGHEST_PROTOCOL)
            for attempt in range(6):
                try:
                    os.replace(tmp, path)
                    return val
                except PermissionError:
                    time.sleep(0.05 * (attempt + 1))
        except Exception:
            pass
        try:
            os.remove(tmp)
        except OSError:
            pass
        return val
