# Raspberry Pi 4 minimal Linux

## Dependencies

```bash
apt-get install --no-install-recommends musl-dev make
wget https://musl.cc/aarch64-linux-musl-cross.tgz
```

Unpack the `musl` cross compiling tool chain somewhere, then add `bin/` to your `$PATH`.

## Compile

```bash
cd src
make
```

## License

[Standard MIT license](LICENSE)

## Links
* [rofl0r/init.c](https://gist.github.com/rofl0r/6168719)
* [Cross compiling for arm or aarch64 on Debian or Ubuntu](https://jensd.be/1126/linux/cross-compiling-for-arm-or-aarch64-on-debian-or-ubuntu)

Project log:

* gemini://callistix.srht.site/projects/minimal_rpi/index.gmi

(download a Gemini browser like [Lagrange](https://git.skyjake.fi/gemini/lagrange) to read the log)
