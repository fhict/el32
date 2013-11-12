#!/bin/sh
printf 'Content-Type: text/html\n\n'
cat << EOF
<html>
<head><title>Hello World!</title></head>
<body><p><b>Hello</b> <i>World</i>!</p></body>
</html>
EOF