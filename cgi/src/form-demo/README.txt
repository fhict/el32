Zeer eenvoudige CGI client
==========================
Deze client maakt gebruik van een HTML form voor input naar het CGI programma en een HTML iframe voor het weergeven van de CGI output.

Open bijgevoegde 'index.html' in je browser (dubbel-klikken) en probeer.
Kijk dan naar de sourcecode.
Let vooral op:
  target="output"
en op:
  iframe name="output"

Het voorbeeld is van de webpagina:

  "Getting Started with CGI Programming in C"
  http://www.cs.tut.fi/~jkorpela/forms/cgic.html

De sourcecode van het CGI programma 'mult.c' staat ook op deze pagina.

In de file 'index.html' staat er bij het form:
  action="http://www.cs.tut.fi/cgi-bin/run/~jkorpela/mult.cgi"

Als mult.cgi op de (Virtuele)Soekris zou staan moet dit natuurlijk zijn:
  action="http://10.0.0.42/cgi-bin/mult.cgi"

Kijk voor wat je nog meer met forms kunt doen op:
http://www.w3schools.com/html/html_forms.asp
Kijk vooral eens naar de Form Examples.
