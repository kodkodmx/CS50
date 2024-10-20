SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE person_id != (SELECT people.id from people where people.name = "Kevin Bacon" AND people.birth = 1958)
AND movie_id IN (SELECT id FROM movies
JOIN stars ON movies.id = stars.movie_id
WHERE person_id = (SELECT people.id from people where people.name = "Kevin Bacon" AND people.birth = 1958));
