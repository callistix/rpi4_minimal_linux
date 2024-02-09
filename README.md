# Raspberry Pi 4 minimal Linux

## Dependencies

```
apt-get install --no-install-recommends musl-dev make
wget https://musl.cc/aarch64-linux-musl-cross.tgz
# unpack somewhere, then add bin/ to your $PATH
```

## Compile

```
cd src
make
```

## Links

* [Cross compiling for arm or aarch64 on Debian or Ubuntu](https://jensd.be/1126/linux/cross-compiling-for-arm-or-aarch64-on-debian-or-ubuntu)
