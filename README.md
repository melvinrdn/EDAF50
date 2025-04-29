# usenet_project, a C++ project

A mini Usenet-like news system in C++17, with two database modes:

Memory: in-memory only, resets on each run.
Disk: persistent on-disk storage using std::filesystem.

## Build

```bash
make
```

## Install

```bash
make install
```

## Clean

```bash
make clean
```

## Usage

### Server

```bash
./news_server <port> [--disk]
```

### Client

```bash
./news_client <host> <port>
```
