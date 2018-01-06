# Nmaya Protocol

Nmaya content arranging protocol with a backronym of "n- Many Aspects Yet Arranged"

## Goals

The NMAYA Protocol (NMAYAP) defines a service for returning material retrieved and indexed from a collection of structured files and announcement to peers of retrieval. Announcements can be used to synchonize display of materials, while retrieval provides easy access to mime-types and bytes for UIs. 

The use case is to provide a layer and bindings for UIs and associated inputs for small and cheap devices that are already exchanging material via gossip protocols. NMAYA allows them to visualize or navigate the shared material in a coordinated or semi-coordinated manner.

For example: two separate devices, each with a screen, could become the left and right pages of a book(a one dimensional ordering by page number(see hydra pair proposal), with one device offset by +1 from the other, and both incrementing by +2). Pressing a button or touchscreen on either device could advance both displayed image(s). 

## Implementation

Currently just a leaky process that sources material from a directory of files in ZPL format structured according to the Hydra Data Model (HDM). Enough to generate python bindings and test with devices. 

TODO server and client model using ipc, zactor for zyre...


## Building
```
git clone git://github.com/zeromq/libzmq.git
git clone git://github.com/zeromq/czmq.git
git clone git://github.com/galencm/nmaya.git

for project in libzmq czmq nmaya; do
    cd $project
    ./autogen.sh && ./configure && make check
    sudo make install && ldconfig
    cd ..
done
```

## Building Notes:

Make sure /usr/local/lib is findable with ldconfig:
`echo '/usr/local/lib' | sudo tee --append /etc/ld.so.conf.d/zmq.conf; sudo ldconfig`

set PKG_CONFIG_PATH env var if library not found, during configure:
`PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/ ./configure`

Remove CPPFLAGS -Werror flag from Makefile:
`sed -i '/^CPPFLAGS/s/-Werror//' Makefile`

## Testing

`make check` looks for a .hydra directory with at least 1 post and 1 image blob:
`cp -r /path/to/.hydra .`