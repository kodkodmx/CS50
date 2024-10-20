SELECT name FROM people WHERE id IN (SELECT DISTINCT people.id FROM people
JOIN directors ON people.id = directors.person_id
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0) ;