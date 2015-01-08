from distutils.core import setup, Extension

gapcoin_hash = Extension('gapcoin_hash',
    sources = [
        'gapcoinmodule.cpp',
        'BlockHeader.cpp',
        'PoW.cpp',
        'PoWUtils.cpp',
    ],
    include_dirs=['.'],
    libraries = ['ssl', 'gmp', 'mpfr', 'crypto'])

setup (name = 'gapcoin_hash',
    version = '1.0',
    ext_modules = [gapcoin_hash])
