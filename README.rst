Skeleton of Jubatus fv_converter Plug-in
=========================================

Based on the ``extract_ascii`` plug-in written by Yuya Unno
(See the `official blog article <http://blog.jubat.us/2012/07/blog-post_18.html>`_ for details).

Requirements
------------

* Jubatus 0.5.0+ (development headers required)

Usage
-----

To build a plug-in, run:

::

  ./waf configure
  ./waf build

You will see the plug-in (a shared library) and an example client in ``build/src`` directory.

Now, change ``EXAMPLE_splitter`` to your project's name and write your own code.

How to Test Plug-Ins
--------------------

* ``jubaconv`` command, bundled with Jubatus, can be used to test your plug-in without running servers. See ``jubaconv_example.sh`` for the usage.
* You can test your plug-in from the RPC layer by using `convchecker <https://github.com/odasatoshi/convchecker/>`_ server written by @odasatoshi.
