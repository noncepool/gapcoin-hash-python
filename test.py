def _test():
    import gapcoin_hash    
        
    header_hex = '02000000cce93da7214414192b753a52a6603f9dd9d910f78e3bff966cefc181f1c397d80fb872152769598c341f9139b14d63d2e95712e50cf8c70e97268d5f7692b775c0c1545400000000000001000e0000001400df7d07'

    hash_int = gapcoin_hash.getpowdiff(header_hex)
    print hash_int # hash_int = 3421862101076924

if __name__ == '__main__':
    _test()
