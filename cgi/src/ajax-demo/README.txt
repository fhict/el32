Ajax en de Soekris.
===================
Auteur: Ruud Ermers

Deze demo demonstreert het gebruik van Ajax, waarbij de webserver op de Soekris draait.
Deze demo maakt geen gebruik van externe libraries (niet op de server, niet op de client) en is bedoeld als startpunt. 

Het werkt als volgt:

In een webbrowser die ajax ondersteunt (bv. firefox) browse je naar de pagina demo.html.
Op deze pagina wordt een XMLHttpRequest gedaan. Dat is niets anders dan een asynchrone http call op de webserver. In dit geval wordt het cgi script cgi_test aangeroepen. Dit is een C applicatie die dus op de server draait. Het resultaat van de request wordt door de client verwerkt en vervolgens wordt een volgend request gedaan.

De toepassing hier (cgi_test ) op de webserver genereert afhankelijk van de huidige tijd een (x,y) coordinaat en schrijft het resultaat(in een format xxx;yyy) naar stdout. 
De client interpreteert het resultaat en genereert op grond hiervan de positie van het 'foo' object. 

Als alles goed is ingesteld beweegt het foo object diagonaal over de pagina.

Om dit zelf te maken doe het volgende:

- Zorg dat je een webserver hebt draaien. (Eenvoudigst is dit eerst te testen onder Windows of Linux, bv. met apache)
- Plaats demo.html in de root van je webserver pages (onder apache is dat /www/htdocs, op de soekris /www   (is allemaal configureerbaar).
- crosscompileer cgi_test.c en plaats het resultaat in de cgi-bin directory (/www/cgi-bin) onder de naam cgi_test (zorg dat ie uitvoerbaar is)

Browse naar demo.htm (bv http://10.0.0.42/demo.html).

Toelichting op de code:

demo.htm:

In doMove wordt een XMLHttpRequest object gemaakt (req). Deze stellen we in op:
- welke webpagina te laden
- welke functie aan te roepen bij 'completion'  (onreadystatechange)
Dit gebeurd in de call req.open.
Vervolgens uitvoeren met req.send.

Hiermee is doMove af.

De completion routine wordt pas uitgevoerd nadat de webserver de betreffende webpagina heeft gegenereerd.
In ons geval is de inhoud van die pagina een tweetal coordinaten, ieder 3 posities, gescheiden door een ;
Zie de functie: onreadystatechange. Deze wordt aangeroepen met status = 200 en dat betekent dat alles ok is. Daar wordt de response uit elkaar gepeuterd en het foo object bewogen. 

cgi.c

Zoals uit het voorgaande blijkt dient het script alleen een (x;y) coordinaat te genereren. Om het leuk te houden is dit gekoppeld aan de tijd.
Het resultaat is dus altijd 'vloeiend' (nou ja...).

Het is belangrijk dat het resultaat voldoet aan de eisen van een webpagina, dus moet je de regel

  printf("Content-type: text/html\n\n");

opnemen! 

De rest is het genereren van de gewenste output via wat moeilijke formules.

Opmerking: Ik heb met opzet wat gecommente regels laten staan in zowel cgi_test.c als demo.html. Handig voor debuggen.






