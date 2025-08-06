# Graph
## Installation
```bash
sudo apt install g++ build-essential cmake clang git -y
git clone https://github.com/MichaelKolesnikov/Graph.git
mkdir Graph/build
cd Graph/build
cmake ..
make
sudo cp libGraph.so /usr/local/lib/
sudo cp -r ../include/Graph /usr/local/include/
sudo ldconfig
```
## Uninstalling
```bash
sudo rm /usr/local/lib/libGraph.so
sudo rm -rf /usr/local/include/Graph
```
